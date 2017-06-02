/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:52:23 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/05/14 15:52:26 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				ps_flag_parse(int ac, char **av)		// need to parse flag structure or something like this
{
	int			count;

	count = 0;
	while (count + 1 < ac && ft_strcmp(av[count + 1], "-d") == 0)
		count++;
	return (count);
}

int				is_sign_or_digit(char ch)
{
	if ((ch >= '0' && ch <= '9') || ch == '-' || ch == '+')
		return (1);
	return (0);
}

int				check_str(const char *str, int (*f)(char))
{
	while (*str)
	{
		if (!(*f)(*str))
			return (0);
		str++;
	}
	return (1);
}

int				stack_is_dup(t_stack *stack, int check_val)
{
	while (stack)
	{
		if (stack->val == check_val)
			return (1);
		stack = stack->next;
	}
	return (0);
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
	ft_putstr(KRED);
	write(2, "Error. ", 7);
	if (message)
		write(2, message, ft_strlen(message));
	write(2, ".\n", 2);
	ft_putstr(KNRM);
	exit(1);
}

void			printf_justified(int *a, int *b)
{
	int			alen;
	int			blen;

	ft_printf("\t| ");
	if (a)
	{
		alen = ft_nbrlen(*a);
		alen = (*a < 0) ? alen - 1 : alen;
		ft_printf("%*s", (10 - alen) / 2, "");
		ft_printf("%-*i", 10 - (10 - alen) / 2, *a);
	}
	else
		ft_printf("%10s", "");
	ft_printf(" || ");
	if (b)
	{
		blen = ft_nbrlen(*b);
		alen = (*b < 0) ? blen - 1 : blen;
		ft_printf("%*s", (10 - blen) / 2, "");
		ft_printf("%-*i", 10 - (10 - blen) / 2, *b);
	}
	else
		ft_printf("%10s", "");
	ft_printf(" |\n");
}

void			debug_put_stacks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a && b)
		{
			printf_justified(&(a->val), &(b->val));
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			printf_justified(&(a->val), NULL);
			a = a->next;
		}
		else
		{
			printf_justified(NULL, &(b->val));
			b = b->next;
		}
	}
}

void			debug_info(t_stack *a, t_stack *b, char *cmd)
{
	if (cmd)
		ft_printf("\n\tCommand: %s\n", cmd);
	ft_printf("\t____________________________\n");
	ft_printf("\t| %10s || %10s |\n", "Stack A ", "Stack B ");
	ft_printf("\t----------------------------\n");
	debug_put_stacks(a, b);
	ft_printf("\t----------------------------\n");
	ft_printf("\n\n");
}

t_stack			*s_el_create(int val)
{
	t_stack		*el;

	el = (t_stack *)malloc(sizeof(t_stack));
	el->val = val;
	el->next = NULL;
	return (el);
}

void			command_dispatcher_c(t_env *env, char *cmd)
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
	if (announce)
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

int				str_arr_free(char **arr)
{
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	return (1);
}

void			put_val_to_stack(t_stack **a, char *arg)
{
	intmax_t	val;

	if (!check_str(arg, &is_sign_or_digit))
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
		put_val_to_stack(&a, str_args[i]);
	if (a == NULL)
		error_call("Memalloc error. Or empty argument list");
	if (n_arg == 1 && str_arr_free(str_args))
		free(str_args);
	return (a);
}

t_env			*init_env(t_stack **a, t_stack **b)
{
	t_env		*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->a = a;
	env->b = b;
	env->sort = NULL;
	env->p_list = NULL;
	return (env);
}
