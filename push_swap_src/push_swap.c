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

void			ft_free_env(t_env *env)
{
	t_stack	*to_free;

	if (env->sort)
		free(env->sort);
	while (*(env->a))
	{
		to_free = pop(env->a);
		to_free->next = NULL;
		free(to_free);
	}
	while (*(env->b))
	{
		to_free = pop(env->b);
		to_free->next = NULL;
		free(to_free);
	}
	free(env);
}

int				main_1(int ac, char **av)
{
	t_stack		*a;
	int			i;
	int			*flags_c_m;
	t_stack		*b;
	t_env		*env;

	a = NULL;
	b = NULL;
	flags_c_m = ps_flag_parse(ac, av);
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
		ft_free_env(env);
	}
	free(flags_c_m);
	return (1);
}

int				main(int ac, char **av)
{
	main_1(ac, av);
	sleep(324234);
	return (0);
}
