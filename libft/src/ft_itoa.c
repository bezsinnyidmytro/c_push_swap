/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:11:26 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/08 15:11:26 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_pos(ssize_t n, int size, char **str)
{
	while (--size >= 0)
	{
		(*str)[size] = (char)(n % 10 + '0');
		n = n / 10;
	}
}

static void		ft_itoa_neg(ssize_t n, int size, char **str)
{
	(*str)[0] = '-';
	while (--size >= 1)
	{
		(*str)[size] = (char)(-(n % 10) + '0');
		n = n / 10;
	}
}

char			*ft_itoa(ssize_t n)
{
	int		size;
	char	*str;

	size = ft_nbrlen(n);
	str = ft_strnew(size);
	if (!str)
		return (char *)(NULL);
	if (n < 0)
		ft_itoa_neg(n, size, &str);
	else
		ft_itoa_pos(n, size, &str);
	return (str);
}
