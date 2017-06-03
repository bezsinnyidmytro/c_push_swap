/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:13:37 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/05/14 15:13:38 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int ac, char **av)
{
	t_stack		*a;
	int			i;
	int			*flags_c_m;
	t_stack		*b;
	t_env		*env;

	a = NULL;
	env = NULL;
	flags_c_m = ps_flag_parse(ac, av);
	b = NULL;
	i = ac - flags_c_m[0];
	if (i > 1)
	{
		a = init_stack(i - 1, av + flags_c_m[0] + 1);
		env = init_env(&a, &b, flags_c_m[1]);
		if (!is_sorted(*(env->a), &srt_asc) && list_size(*(env->a)) < 7)
			small_stack_sort(env);
		else if (!is_sorted(*(env->a), &srt_asc))
			stack_main_split(env);
		if ((flags_c_m[1] & 4) == 4)
			ft_printf("\tNumber of used operations: %i\n", env->op_count);
	}
	return (1);
}
