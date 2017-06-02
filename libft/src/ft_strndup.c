/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:54:47 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/02 12:54:48 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, unsigned int n)
{
	char				*str_new;
	unsigned int		i;

	if (!s1)
		return (NULL);
	i = 0;
	str_new = ft_strnew(n);
	if (!str_new)
		return (NULL);
	while (s1[i] && i < n)
	{
		str_new[i] = s1[i];
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
