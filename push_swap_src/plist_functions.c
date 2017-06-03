/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plist_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:12:54 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 16:12:54 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_plist		*plist_el_create(int val, char to)
{
	t_plist	*el;

	el = (t_plist *)malloc(sizeof(t_plist));
	el->count = val;
	el->to = to;
	el->b_is_rot = 0;
	el->next = NULL;
	return (el);
}

void		plist_push(t_plist **s_top, t_plist *s_el)
{
	t_plist	*old_top;

	if (s_el)
	{
		old_top = *s_top;
		*s_top = s_el;
		(*s_top)->next = old_top;
	}
}

void		plist_pop_free(t_plist **s_top)
{
	t_plist	*to_free;

	to_free = NULL;
	if (*s_top)
	{
		to_free = *s_top;
		*s_top = (*s_top)->next;
	}
	to_free->next = NULL;
	free(to_free);
}

void		plist_removeifa(t_plist **s_top)
{
	t_plist	*to_free;

	if ((*s_top)->next)
		plist_removeifa(&((*s_top)->next));
	if ((*s_top)->to == 'A')
	{
		to_free = (*s_top);
		(*s_top) = (*s_top)->next;
		to_free->next = NULL;
		free(to_free);
	}
}
