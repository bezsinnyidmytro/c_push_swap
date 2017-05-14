/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:45:38 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/06 16:45:39 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;

	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	n = ft_strlen(s);
	while (n > 0)
	{
		if (s[n - 1] == c)
			return ((char *)&s[n - 1]);
		n--;
	}
	return (NULL);
}
