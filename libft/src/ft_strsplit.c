/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:39:44 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/08 17:39:45 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fill_tab(char const *s, char ***word_tab, int words,
	char c)
{
	int				i;
	unsigned int	start;
	unsigned int	j;

	i = -1;
	j = 0;
	while (++i < words)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		start = j;
		while (s[j] != '\0' && s[j] != c)
			j++;
		(*word_tab)[i] = ft_strsub(s, start, (size_t)(j - start));
	}
	(*word_tab)[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**word_tab;
	int		i;

	if (!s || !c)
		return (NULL);
	words = ft_countwords(s, c);
	word_tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!word_tab)
		return (NULL);
	ft_fill_tab(s, &word_tab, words, c);
	i = -1;
	while (++i < words)
	{
		if (!word_tab[i])
			return (NULL);
	}
	return (word_tab);
}
