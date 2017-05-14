/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:53:52 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/07 14:53:53 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *s1;

	s1 = s;
	while (n--)
	{
		if (*s1 == (unsigned char)c)
			return ((void *)s1);
		s1++;
	}
	return (void *)(NULL);
}
