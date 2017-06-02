/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfputstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:37:56 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/02 13:37:57 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void				ft_pfputstr(t_pfarg *arg, int fd)
{
	char	ch;

	ch = '\0';
	if (arg->is_zero_char == 1 && (arg->fmt_flags & 4) == 4)
		write(fd, &ch, 1);
	ft_fdputstr(arg->cnt, fd);
	if (arg->is_zero_char == 1 && (arg->fmt_flags | 4) != arg->fmt_flags)
		write(fd, &ch, 1);
}
