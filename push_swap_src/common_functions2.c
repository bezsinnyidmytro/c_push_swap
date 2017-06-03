/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:53:32 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 15:53:33 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		command_dispatcher_c(t_env *env, char *cmd)
{
	t_stack		**a;
	t_stack		**b;

	a = env->a;
	b = env->b;
	if (ft_strcmp(cmd, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(cmd, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(cmd, "rra") == 0)
		rrotate(a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		rrotate(b);
	else if (ft_strcmp(cmd, "rrr") == 0)
	{
		rrotate(a);
		rrotate(b);
	}
	else
		error_call(ft_strjoin("Invalid instruction: ", cmd));
}

void			command_dispatcher(t_env *env, char *cmd, int announce)
{
	t_stack		**a;
	t_stack		**b;

	a = env->a;
	b = env->b;
	if ((announce || (env->flag_mask & 1) == 1) && (++(env->op_count)))
		ft_printf("%s\n", cmd);
	if (ft_strcmp(cmd, "pa") == 0)
		push(a, pop(b));
	else if (ft_strcmp(cmd, "pb") == 0)
		push(b, pop(a));
	else if (ft_strcmp(cmd, "sa") == 0)
		swap(a);
	else if (ft_strcmp(cmd, "sb") == 0)
		swap(b);
	else if (ft_strcmp(cmd, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(cmd, "ra") == 0)
		rotate(a);
	else
		command_dispatcher_c(env, cmd);
}

t_env			*init_env(t_stack **a, t_stack **b, int flag_mask)
{
	t_env		*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->a = a;
	env->b = b;
	env->sort = NULL;
	env->p_list = NULL;
	env->flag_mask = flag_mask;
	env->op_count = 0;
	return (env);
}
