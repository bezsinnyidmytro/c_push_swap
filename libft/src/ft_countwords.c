/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:55:11 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/08 17:55:15 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int		num_words;

	num_words = 0;
	if (*s == '\0')
		return (0);
	while (*s == c)
		s++;
	while (*s != '\0')
	{
		if (*s == c && *(s - 1) != c)
			num_words++;
		s++;
	}
	if (*(s - 1) != c)
		num_words++;
	return (num_words);
}
