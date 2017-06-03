/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_split_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:38:57 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/02 18:39:04 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	restore_a(t_env *env, int *rot_ca)
{
	if (*rot_ca > 0)
	{
		while ((*rot_ca)--)
			command_dispatcher(env, "rra", 1);
	}
	else if (*rot_ca < 0)
	{
		while ((*rot_ca)++)
			command_dispatcher(env, "ra", 1);
	}
	*rot_ca = 0;
}

static void	sort_three_wrapper(t_env *env, int *rot_ca, t_plist *a_push)
{
	int		numb;

	numb = ((*(env->p_list))->to == 'B') ?
		(*(env->p_list))->count : (*(env->p_list))->next->count;
	restore_a(env, rot_ca);
	sort_three(env, a_push, numb);
	plist_removeifa(env->p_list);
	if (numb != 0)
		plist_pop_free(env->p_list);
}

static void	stacks_sort(t_env *env, int full_size)
{
	t_plist	*a_push;
	int		piv;
	int		piv2;
	int		sort_size;
	int		rot_ca;

	rot_ca = 0;
	while (*(env->p_list))
	{
		sort_size = list_size(*(env->a));
		piv2 = env->sort[(2 * full_size - 2 * sort_size -
			(*(env->p_list))->count) / 2];
		if ((*(env->p_list))->to == 'B' && (*(env->p_list))->count > 3)
			a_push = backpush_a(env, piv2);
		else if ((*(env->p_list))->to == 'B' && (*(env->p_list))->count <= 3)
			a_push = NULL;
		while (a_push && a_push->count > 3)
		{
			piv = env->sort[(2 * full_size - sort_size -
				list_size(*(env->a))) / 2];
			plist_push(env->p_list, backpush_b(env, piv, &a_push, &rot_ca));
		}
		sort_three_wrapper(env, &rot_ca, a_push);
	}
}

static void	sort_init(t_env *env, t_plist **push_list, int stack_len)
{
	int		numb;

	numb = (*push_list)->count > 3 ? 0 : (*push_list)->count;
	sort_three(env, NULL, numb);
	if (numb != 0)
		plist_pop_free(push_list);
	env->p_list = push_list;
	stacks_sort(env, stack_len);
}

void		stack_main_split(t_env *env)
{
	int		stack_len;
	t_plist *push_list;
	int		piv;
	int		pushed_total;
	int		pushed;

	push_list = NULL;
	stack_len = list_size(*(env->a));
	env->sort = list_to_arr_sort(*(env->a));
	pushed_total = 0;
	while (list_size(*(env->a)) > 3)
	{
		pushed = 0;
		piv = env->sort[(stack_len + pushed_total) / 2];
		while (has_lower_piv(*(env->a), piv))
		{
			while ((*(env->a))->val >= piv)
				command_dispatcher(env, "ra", 1);
			command_dispatcher(env, "pb", 1);
			pushed++;
		}
		plist_push(&push_list, plist_el_create(pushed, 'B'));
		pushed_total += pushed;
	}
	sort_init(env, &push_list, stack_len);
}
