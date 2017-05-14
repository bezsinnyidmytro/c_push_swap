/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:48:51 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/06 15:48:52 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(s1);
	if (j >= n)
		return (n + ft_strlen(s2));
	i = 0;
	while (s2[i] != '\0' && i < n - j - 1)
	{
		s1[j + i] = s2[i];
		i++;
	}
	s1[j + i] = '\0';
	return (j + ft_strlen(s2));
}
