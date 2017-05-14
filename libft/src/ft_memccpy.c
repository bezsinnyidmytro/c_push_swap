/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:06:39 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/07 14:06:40 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*s1;
	const unsigned char		*s2;

	s1 = dst;
	s2 = src;
	while (n--)
	{
		*s1 = *s2;
		if (*s2 == (unsigned char)c)
			return ((void *)(++s1));
		s1++;
		s2++;
	}
	return (void *)(NULL);
}
