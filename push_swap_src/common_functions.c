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

int			ps_flag_parse(int ac, char **av)		// need to parse flag structure or something like this
{
	int 	count;

	count = 0;
	while (count + 1 < ac && ft_strcmp(av[count + 1], "-d") == 0)
		count++;
	return (count);
}

int			is_sign_or_digit(char ch)
{
	if ((ch >= '0' && ch <= '9') || ch == '-' || ch == '+')
		return (1);
	return (0);
}

int			check_str(const char *str, int (*f)(char))			// need to trim and check if it's not empty
{
	while (*str)
	{
		if (!(*f)(*str))
			return (0);
		str++;
	}
	return (1);
}

int			stack_is_dup(t_stack *stack, int check_val)
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
	write(2, "\n", 1);
	//ft_putstr(KWHT);
	//ft_putstr("This should be another color.\n");
	exit(1);
}

void			debug_info(t_stack const *a, t_stack const *b, char *cmd)
{
	t_stack		*iter;

	if (cmd)
		printf("\n\tCommand: %s\n", cmd);
	iter = (t_stack *)a;
	printf("\tStack A:\n\t\t");
	while (iter)
	{
		printf("%*d", ft_nbrlen(iter->val) + 3, iter->val);
		iter = iter->next;
	}
	iter = (t_stack *)b;
	printf("\n\tStack B:\n\t\t");
	while (iter)
	{
		printf("%*d", ft_nbrlen(iter->val) + 3, iter->val);
		iter = iter->next;
	}
	printf("\n\n");
	//printf("Input a command (pa, pb, sa, sb, ra, rb, rr, rra, rrb, rrr):\n");
	fflush(stdout);
}

t_stack			*s_el_create(int val)
{
	t_stack		*el;

	el = (t_stack *)malloc(sizeof(t_stack));
	el->val = val;
	el->next = NULL;
	return (el);
}

void			command_dispatcher(t_stack **a, t_stack **b, char *cmd, int announce)
{
	if (announce)
		printf("%s\n", cmd);
	if (ft_strcmp(cmd, "pa") == 0)
	{
		//printf("Pushed to A: %i\n", (*b)->val);
		push(a, pop(b));
	}
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
	else if (ft_strcmp(cmd, "rb") == 0)
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
	{
		//error_call("Invalid instruction.");
		error_call(ft_strjoin("Invalid instruction. ", cmd));
	}
}

t_stack			*init_stack(int n_arg, char **av)
{
	// Emty string "" is parsed as 0 - need to trim and check if the string is not emty
	t_stack		*a;
	int			i;
	intmax_t	val;
	char		**str_args;

	//command = NULL;
	a = NULL;
	i = n_arg;
	str_args = av;
	if (n_arg == 1)
	{
		str_args = ft_strsplit(av[0], ' ');
		i = ft_countwords(av[0], ' ');
	}
	//debug = 0;
	// if (ft_strcmp(av[1], "-d") == 0 && (debug = 1))
	// 	arg_bound++;
	// Push element to the A
	while (--i >= 0)
	{
		if (!check_str(str_args[i], &is_sign_or_digit))
		{
			//printf("%s\n", str_args[i]);
			error_call("Bad INTEGER input.");
		}
		val = ft_atoimax(str_args[i]);
		//printf("Converted integer is %zi\n", val);
		if (val < INT_MIN || val > INT_MAX)
			error_call("Value is out of INTEGER range.");
		if (stack_is_dup(a, val))
			error_call("Integer value duplicates are forbidden.");
		push(&a, s_el_create(val));
	}
	if (a == NULL)					// set for UBUNTU
		error_call("Memalloc error. Or empty argument list.");
	//list_to_arr_sort(a);
	return (a);
}
