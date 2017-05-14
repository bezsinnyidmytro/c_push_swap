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

int				main(int ac, char **av)
{
	// int			fd;
	// char		*line;

	// line = NULL;
	// if (ac > 1)
	// {
	// 	fd = open(av[1], O_RDONLY);
	// 	while (get_next_line(fd, &line))
	// 	{
	// 		printf("%s\n", line);
	// 		free(line);
	// 	}
	// 	close(fd);
	// }
	
	t_stack		*a;
	// t_stack		*iter;
	// t_stack		*pop_el;
	int			i;
	t_stack		*b;
	char		*command;
	int			debug;
	int			arg_bound;

	command = NULL;
	a = NULL;
	b = NULL;
	i = ac;
	debug = 0;
	if (i > 1)
	{
		arg_bound = 0;
		if (ft_strcmp(av[1], "-d") == 0 && (debug = 1))
			arg_bound++;
		// Push element to the A
		while (--i > arg_bound)
			push(&a, s_el_create(ft_atoi(av[i])));
		
		// iter = a;
		// printf("\tStack A:\n\t\t");
		// while (iter)
		// {
		// 	printf("%5d", iter->val);
		// 	iter = iter->next;
		// }
		// iter = b;
		// printf("\n\tStack B:\n\t\t");
		// while (iter)
		// {
		// 	printf("%5d", iter->val);
		// 	iter = iter->next;
		// }
		// printf("\n");
		// fflush(stdout);

		// printf("Input a command (pa, pb, sa, sb, ra, rb, rr, rra, rrb, rrr):\n");
		// fflush(stdout);

		// Read commnd on standard input and process it
		while ((get_next_line(0, &command)))
		{
			command_dispatcher(&a, &b, command, 0);
			if (debug)
				debug_info(a, b, command);
		}

		// Push elements from A to B
		// while ((pop_el = pop(&a)) != NULL)
		// 	push(&b, pop_el);
		
		if (is_sorted(a, &srt_asc) && !b)
			printf("%sOK\n", KGRN);
		else
			printf("%sKO\n", KRED);
		// if (!debug)
		// {
		// 	// Print values form A
		// 	printf("\nStack A after processing commands:\n");
		// 	while (a)
		// 	{
		// 		printf("%d ", a->val);
		// 		a = a->next;
		// 	}

		// 	// Print values from B
		// 	printf("\nStack B after processing commands:\n");
		// 	while (b)
		// 	{
		// 		printf("%d ", b->val);
		// 		b = b->next;
		// 	}
		// 	printf("\n");
		// }
	}

	return (1);
}











