/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:24:05 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/07 14:24:06 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	s1 = dst;
	s2 = src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i--)
			s1[i] = s2[i];
	}
	return (dst);
}
