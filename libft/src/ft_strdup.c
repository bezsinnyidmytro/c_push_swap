/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:37:52 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/06 14:37:53 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned long int	size;
	char				*str_new;
	int					i;

	i = 0;
	size = ft_strlen(s1);
	str_new = (char *)malloc(sizeof(char) * (size + 1));
	if (!str_new)
		return (NULL);
	while (s1[i])
	{
		str_new[i] = s1[i];
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
