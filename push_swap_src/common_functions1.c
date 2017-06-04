/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:48:34 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 15:48:35 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				*ps_flag_parse(int ac, char **av)
{
	int			*res_c_m;

	res_c_m = (int *)malloc(sizeof(int) * 2);
	res_c_m[0] = 0;
	res_c_m[1] = 0;
	while (res_c_m[0] + 1 < ac && (ft_strcmp(av[res_c_m[0] + 1], "-d") == 0 ||
		ft_strcmp(av[res_c_m[0] + 1], "-t") == 0 ||
		ft_strcmp(av[res_c_m[0] + 1], "-w") == 0))
	{
		if (ft_strcmp(av[res_c_m[0] + 1], "-d") == 0)
			res_c_m[1] = (res_c_m[1] | 1);
		if (ft_strcmp(av[res_c_m[0] + 1], "-t") == 0)
			res_c_m[1] = (res_c_m[1] | 2);
		if (ft_strcmp(av[res_c_m[0] + 1], "-w") == 0)
			res_c_m[1] = (res_c_m[1] | 4);
		res_c_m[0]++;
	}
	return (res_c_m);
}

int				srt_asc(int a, int b)
{
	return (b >= a);
}

int				is_sorted(t_stack *s_top, int (*f)())
{
	t_stack		*tmp;

	tmp = s_top;
	while (tmp->next)
	{
		if (!(*f)(tmp->val, tmp->next->val))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void			error_call(char *message)
{
	ft_putstr_fd(KRED, 2);
	//write(2, "Error. ", 7);
	ft_putstr_fd("Error. ", 2);
	if (message)
		ft_putstr_fd(message, 2); //write(2, message, ft_strlen(message));
	ft_putstr_fd(".\n", 2); //write(2, ".\n", 2);
	ft_putstr_fd(KNRM, 2);
	//sleep(2324234);
	exit(1);				// exit should not be here
}

t_stack			*s_el_create(int val)
{
	t_stack		*el;

	el = (t_stack *)malloc(sizeof(t_stack));
	el->val = val;
	el->next = NULL;
	return (el);
}
