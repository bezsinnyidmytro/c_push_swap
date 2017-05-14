/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:13:35 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/09 16:13:35 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list			*ft_strsplit_lst(char const **word_tab)
{
	t_list	*word_list;
	int		i;

	word_list = NULL;
	if (word_tab)
	{
		i = 0;
		if (word_tab[i])
		{
			word_list = ft_lstnew(word_tab[i], ft_strlen(word_tab[i]) + 1);
			i++;
		}
		while (word_tab[i++])
			ft_lstadd_back(word_list, ft_lstnew(word_tab[i - 1],
				ft_strlen(word_tab[i - 1]) + 1));
	}
	return (word_list);
}
