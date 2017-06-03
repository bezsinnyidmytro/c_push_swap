/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_split_addon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:34:33 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 16:34:34 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			has_lower_piv(t_stack *a, int piv)
{
	while (a)
	{
		if (a->val < piv)
			return (1);
		a = a->next;
	}
	return (0);
}

int			has_higher_piv(t_stack *b, int piv)
{
	while (b)
	{
		if (b->val >= piv)
			return (1);
		b = b->next;
	}
	return (0);
}

void		common_triple_cmd(t_env *env)
{
	command_dispatcher(env, "rr", 1);
	command_dispatcher(env, "ss", 1);
	command_dispatcher(env, "rrr", 1);
}

void		run_triple_cmd(t_env *env, char stack, int mask)
{
	if (stack == 'a')
	{
		if ((mask & 1) == 1)
			command_dispatcher(env, "ra", 1);
		if ((mask & 2) == 2)
			command_dispatcher(env, "sa", 1);
		if ((mask & 4) == 4)
			command_dispatcher(env, "rra", 1);
	}
	else if (stack == 'b')
	{
		if ((mask & 1) == 1)
			command_dispatcher(env, "rb", 1);
		if ((mask & 2) == 2)
			command_dispatcher(env, "sb", 1);
		if ((mask & 4) == 4)
			command_dispatcher(env, "rrb", 1);
	}
}

int			ord_l(int el, int piv)
{
	return (el < piv);
}
