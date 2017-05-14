/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:19:49 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/06 16:19:50 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pointer;

	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	pointer = (char *)s;
	while (*pointer)
	{
		if (*pointer == c)
			return (pointer);
		pointer++;
	}
	return (NULL);
}
