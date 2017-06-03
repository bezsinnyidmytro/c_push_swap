/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:10:27 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 16:10:28 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	min_val_pos(t_stack *ss)
{
	int		min;
	int		i;
	int		min_idx;

	min = ss->val;
	i = 1;
	min_idx = i;
	while (ss)
	{
		if (ss->val < min)
		{
			min = ss->val;
			min_idx = i;
		}
		i++;
		ss = ss->next;
	}
	return (min_idx);
}

void		small_stack_sort(t_env *env)
{
	int		min_ord;

	while (list_size(*(env->a)) > 3)
	{
		min_ord = min_val_pos(*(env->a));
		if (min_ord <= list_size(*(env->a)) / 2)
			while (--min_ord)
				command_dispatcher(env, "ra", 1);
		else
			while (min_ord++ <= list_size(*(env->a)))
				command_dispatcher(env, "rra", 1);
		command_dispatcher(env, "pb", 1);
	}
	if (list_size(*(env->a)) > 1)
		if ((*(env->a))->val > (*(env->a))->next->val)
			command_dispatcher(env, "sa", 1);
	if (list_size(*(env->a)) == 3)
	{
		if ((*(env->a))->next->next->val < (*(env->a))->next->val)
			command_dispatcher(env, "rra", 1);
		if ((*(env->a))->val > (*(env->a))->next->val)
			command_dispatcher(env, "sa", 1);
	}
	while (list_size(*(env->b)) > 0)
		command_dispatcher(env, "pa", 1);
}
