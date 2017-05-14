/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:24:49 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/08 12:24:50 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_new;
	size_t			len;

	if (!s)
		return (char *)(NULL);
	len = ft_strlen(s);
	str_new = ft_strnew(len);
	if (!str_new)
		return (char *)(NULL);
	while (len--)
		str_new[len] = f(len, s[len]);
	return (str_new);
}
