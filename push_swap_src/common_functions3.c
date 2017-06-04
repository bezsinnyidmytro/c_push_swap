/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:58:09 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 15:58:11 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		check_str(const char *str, int (*f)(char))
{
	while (*str)
	{
		if (!(*f)(*str))
			return (0);
		str++;
	}
	return (1);
}

static int		stack_is_dup(t_stack *stack, int check_val)
{
	while (stack)
	{
		if (stack->val == check_val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int		str_arr_free(char **arr)
{
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	return (1);
}

static void		put_val_to_stack(t_stack **a, char *arg)
{
	intmax_t	val;

	if (!check_str(arg, &is_sign_or_digit))				// need to free stack_a on error (can't be monitored)
		error_call("Bad INTEGER input");
	val = ft_atoimax(arg);
	if (val < INT_MIN || val > INT_MAX)
		error_call("Value is out of INTEGER range");
	if (stack_is_dup(*a, val))
		error_call("Integer value duplicates are forbidden");
	push(a, s_el_create(val));
}

t_stack			*init_stack(int n_arg, char **av)
{
	t_stack		*a;
	int			i;
	char		**str_args;

	a = NULL;
	i = n_arg;
	str_args = av;
	if (n_arg == 1)
	{
		str_args = ft_strsplit(av[0], ' ');
		i = ft_countwords(av[0], ' ');
		if (i == 0)
			exit(1);
	}
	while (--i >= 0)
		put_val_to_stack(&a, str_args[i]);				// need to free str_args on n_arg == 1 and error (can't be monitored)
	if (a == NULL)
		error_call("Memalloc error. Or empty argument list");
	if (n_arg == 1 && str_arr_free(str_args))
		free(str_args);
	return (a);
}
