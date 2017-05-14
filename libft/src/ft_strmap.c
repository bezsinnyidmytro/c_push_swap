/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:02:48 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/08 12:02:49 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str_new;
	char	*str_start;

	if (!s)
		return (char *)(NULL);
	str_new = ft_strnew(ft_strlen(s));
	if (!str_new)
		return (char *)(NULL);
	str_start = str_new;
	while (*s)
	{
		*str_new = f(*s);
		str_new++;
		s++;
	}
	return (str_start);
}
