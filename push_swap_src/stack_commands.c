/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:43:56 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/05/14 14:43:57 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			push(t_stack **s_top, t_stack *s_el)
{
	t_stack		*old_top;

	if (s_el)
	{
		old_top = *s_top;
		*s_top = s_el;
		(*s_top)->next = old_top;
	}
}

t_stack			*pop(t_stack **s_top)
{
	t_stack		*res;

	res = NULL;
	if (*s_top)
	{
		res = *s_top;
		*s_top = (*s_top)->next;
	}
	return (res);
}

void			swap(t_stack **s_top)
{
	t_stack			*second;

	if ((*s_top) && (*s_top)->next)
	{
		second = (*s_top)->next;
		(*s_top)->next = (*s_top)->next->next;
		second->next = (*s_top);
		(*s_top) = second;
	}
}

void			rotate(t_stack **s_top)
{
	t_stack		*old_top;
	t_stack		*iter;

	if ((*s_top) && (*s_top)->next)
	{
		old_top = (*s_top);
		(*s_top) = (*s_top)->next;
		old_top->next = NULL;
		iter = (*s_top);
		while (iter->next)
			iter = iter->next;
		iter->next = old_top;
	}
}

void			rrotate(t_stack **s_top)
{
	t_stack		*last;
	t_stack		*pre_last;

	if ((*s_top) && (*s_top)->next)
	{
		pre_last = (*s_top);
		while (pre_last->next->next)
			pre_last = pre_last->next;
		last = pre_last->next;
		pre_last->next = NULL;
		last->next = (*s_top);
		(*s_top) = last;
	}
}
