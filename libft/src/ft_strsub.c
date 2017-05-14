/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:05:19 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/08 13:05:20 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	if (!s)
		return (NULL);
	substr = ft_strnew(len);
	if (!substr)
		return (NULL);
	while (len--)
		substr[len] = s[start + len];
	return (substr);
}
