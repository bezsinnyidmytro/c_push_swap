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

	printf("\n\tCommand: %s\n", cmd);
	iter = (t_stack *)a;
	printf("\tStack A:\n\t\t");
	while (iter)
	{
		printf("%5d", iter->val);
		iter = iter->next;
	}
	iter = (t_stack *)b;
	printf("\n\tStack B:\n\t\t");
	while (iter)
	{
		printf("%5d", iter->val);
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
		error_call("Invalid instruction.");
}
