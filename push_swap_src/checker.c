/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 13:52:11 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/05/11 13:52:12 by dbezsinn         ###   ########.fr       */
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

void			process_commands(t_env *env, int *flags_c_m)
{
	char		*command;

	command = NULL;
	if ((flags_c_m[1] & 1) == 1)
		debug_info(*(env->a), *(env->b), NULL, flags_c_m[1]);
	while ((get_next_line(0, &command)))
	{
		command_dispatcher(env, command, 0);
		if ((flags_c_m[1] & 1) == 1)
			debug_info(*(env->a), *(env->b), command, flags_c_m[1]);
		free(command);
	}
}

int				main_1(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			*flags_c_m;
	t_env		*env;
	int			i;

	a = NULL;
	b = NULL;
	flags_c_m = ps_flag_parse(ac, av);
	i = ac - flags_c_m[0];
	if (i > 1)
	{
		a = init_stack(i - 1, av + flags_c_m[0] + 1);
		env = init_env(&a, &b, flags_c_m[1]);
		process_commands(env, flags_c_m);
		if ((flags_c_m[1] & 4) == 4)
			ft_printf("\tNumber of used operations: %i\n", env->op_count);
		if (is_sorted(*(env->a), &srt_asc) && !(*(env->b)))
			ft_printf("%sOK%s\n", KGRN, KNRM);
		else
			ft_printf("%sKO%s\n", KRED, KNRM);
		ft_free_env(env);
	}
	free(flags_c_m);
	return (1);
}

int				main(int ac, char **av)
{
	main_1(ac, av);
	sleep(1233435);
	return (0);
}
