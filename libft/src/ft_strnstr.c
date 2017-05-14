/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:52:54 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/07 11:52:55 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;
	int flag;

	i = -1;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[++i] != '\0')
	{
		flag = 1;
		j = -1;
		while (little[++j] != '\0')
		{
			if (little[j] != big[i + j] || (size_t)(i + j) >= len)
			{
				flag = 0;
				break ;
			}
		}
		if (flag == 1)
			return ((char *)&big[i]);
	}
	return (NULL);
}
