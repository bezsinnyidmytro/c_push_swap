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

int				list_size(t_stack *list)
{
	int		count;

	count = 0;
	while (list && (++count))
		list = list->next;
	return (count);
}

int				is_sign_or_digit(char ch)
{
	if ((ch >= '0' && ch <= '9') || ch == '-' || ch == '+')
		return (1);
	return (0);
}

static void		printf_justified(int *a, int *b)
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

static void		debug_put_stacks(t_stack *a, t_stack *b)
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

void			debug_info(t_stack *a, t_stack *b, char *cmd, int flag_mask)
{
	if (cmd)
		ft_printf("\n\tCommand: %s\n", cmd);
	ft_printf("\t____________________________\n");
	ft_printf("\t| %10s || %10s |\n", "Stack A ", "Stack B ");
	ft_printf("\t----------------------------\n");
	debug_put_stacks(a, b);
	ft_printf("\t----------------------------\n");
	ft_printf("\n\n");
	if ((flag_mask & 2) == 2)
		sleep(1);
}
