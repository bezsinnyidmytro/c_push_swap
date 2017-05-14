/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:19:26 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/09 14:19:27 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf_e;
	t_list	*l_start;

	if (!lst)
		return (NULL);
	buf_e = (*f)(lst);
	l_start = buf_e;
	if (!l_start)
		return (NULL);
	while (lst->next)
	{
		buf_e->next = (*f)(lst->next);
		buf_e = buf_e->next;
		lst = lst->next;
	}
	return (l_start);
}
