/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:47:19 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/08 13:47:20 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;

	if (!s)
		return (char *)(NULL);
	start = 0;
	len = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (start == len + 1)
		return (ft_strnew(0));
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	len = len - start + 1;
	return (ft_strsub(s, start, len));
}
