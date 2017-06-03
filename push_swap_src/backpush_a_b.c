/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backpush_a_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:38:39 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 16:38:42 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	rot_or_rrot(t_stack *stack, int piv, int (*ord)(), int (*has)())
{
	int		first;
	int		last;
	int		stack_size;

	stack_size = list_size(stack);
	first = 1;
	while (1)
	{
		if ((*ord)(stack->val, piv))
			break ;
		first++;
		stack = stack->next;
	}
	last = first;
	stack = stack->next;
	while ((*has)(stack, piv))
	{
		last++;
		stack = stack->next;
	}
	if (first > stack_size / 2 && last > stack_size / 2)
		return (0);
	return (1);
}

static int	backpush_a_addon(t_env *env, int piv, int *i, int plist_len)
{
	while (has_higher_piv(*(env->b), piv) && (*(env->b))->val < piv)
	{
		if (!((*(env->p_list))->b_is_rot))
			command_dispatcher(env, "rb", 1);
		else
			command_dispatcher(env, "rrb", 1);
		(*i)++;
	}
	command_dispatcher(env, "pa", 1);
	(*i)++;
	if (!has_higher_piv(*(env->b), piv) && (*i) < plist_len)
	{
		while ((*i) < plist_len)
		{
			if (!((*(env->p_list))->b_is_rot))
				command_dispatcher(env, "rb", 1);
			else
				command_dispatcher(env, "rrb", 1);
			(*i)++;
		}
	}
	return (1);
}

t_plist		*backpush_a(t_env *env, int piv)
{
	int		pushed;
	int		i;
	int		plist_len;

	pushed = 0;
	i = 0;
	plist_len = (*(env->p_list))->count;
	if ((*(env->p_list))->b_is_rot == 1)
		plist_len += (plist_len + 1) / 2;
	while (i < plist_len)
		pushed += backpush_a_addon(env, piv, &i, plist_len);
	(*(env->p_list))->b_is_rot = (*(env->p_list))->b_is_rot ? 0 : 1;
	(*(env->p_list))->count -= pushed;
	i = plist_len - pushed;
	if ((*(env->p_list))->count <= 3)
	{
		if ((*(env->p_list))->b_is_rot)
		{
			while (i--)
				command_dispatcher(env, "rrb", 1);
			(*(env->p_list))->b_is_rot = 0;
		}
	}
	plist_push(env->p_list, plist_el_create(pushed, 'A'));
	return (*(env->p_list));
}

t_plist		*backpush_b(t_env *env, int piv, t_plist **a_push, int *rot_ca)
{
	int		pushed;
	int		r_or_rr;

	pushed = 0;
	while (has_lower_piv(*(env->a), piv))
	{
		r_or_rr = rot_or_rrot(*(env->a), piv, &ord_l, &has_lower_piv);
		while ((*(env->a))->val >= piv)
		{
			if (r_or_rr)
			{
				command_dispatcher(env, "ra", 1);
				(*rot_ca)++;
			}
			else
			{
				command_dispatcher(env, "rra", 1);
				(*rot_ca)--;
			}
		}
		command_dispatcher(env, "pb", 1);
		pushed++;
	}
	(*a_push)->count -= pushed;
	return (plist_el_create(pushed, 'B'));
}
