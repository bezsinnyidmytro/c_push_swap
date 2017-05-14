/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:51:53 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/09 18:51:54 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_lst_concat(t_list *lst)
{
	size_t	content_size;
	t_list	*list_st;
	char	*str;

	list_st = lst;
	content_size = 0;
	while (list_st)
	{
		content_size += list_st->content_size - 1;
		list_st = list_st->next;
	}
	str = ft_strnew(content_size);
	while (lst)
	{
		ft_strlcat(str, lst->content, content_size + 1);
		lst = lst->next;
	}
	return (str);
}
