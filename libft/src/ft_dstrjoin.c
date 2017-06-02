/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:29:17 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/02 13:29:19 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dstrjoin(char *s1, char *s2, int ff1, int ff2)
{
	size_t	len;
	char	*str_new;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str_new = ft_strnew(len);
	if (!str_new)
		return (NULL);
	str_new = ft_strcat(str_new, s1);
	str_new = ft_strcat(str_new, s2);
	if (ff1)
		free(s1);
	if (ff2)
		free(s2);
	return (str_new);
}
