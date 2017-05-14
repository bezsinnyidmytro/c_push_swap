/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:59:48 by dbezsinn          #+#    #+#             */
/*   Updated: 2016/12/06 13:59:49 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_strlen(const char *str)
{
	unsigned long int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
