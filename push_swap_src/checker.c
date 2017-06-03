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
	// 		ft_printf("%s\n", line);
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
	int			flags_count;
	t_env		*env;
	//char		**arg_s;

	command = NULL;
	a = NULL;
	b = NULL;
	flags_count = ps_flag_parse(ac, av);
	//ft_printf("The flag_count: %i\n", flag_count);
	i = ac - flags_count;
	//ft_printf("The i = ac - flag_count: %i\n", i);
	debug = flags_count ? 1 : 0;
	if (i > 1)
	{
		// if (i == 2)
		// {
		// 	arg_s = ft_strsplit(av[1], ' ');
		// 	a = init_stack(ft_countwords(av[1], ' '), arg_s, -1);									// if split is used arg_s[0] should be used
		// }
		//else
		a = init_stack(i - 1, av + flags_count + 1);
		env = init_env(&a, &b);
		// if (ft_strcmp(av[1], "-d") == 0 && (debug = 1))		// need to modify in case when ac == 2
		// 	arg_bound++;
		
		
		// // Push element to the A
		// while (--i > arg_bound)
		// 	push(&a, s_el_create(ft_atoi(arg_s[i])));
		
		// iter = a;
		// ft_printf("\tStack A:\n\t\t");
		// while (iter)
		// {
		// 	ft_printf("%5d", iter->val);
		// 	iter = iter->next;
		// }
		// iter = b;
		// ft_printf("\n\tStack B:\n\t\t");
		// while (iter)
		// {
		// 	ft_printf("%5d", iter->val);
		// 	iter = iter->next;
		// }
		// ft_printf("\n");
		// fflush(stdout);

		// ft_printf("Input a command (pa, pb, sa, sb, ra, rb, rr, rra, rrb, rrr):\n");
		// fflush(stdout);

		if (debug)
			debug_info(*(env->a), *(env->b), NULL);

		// Read commnd on standard input and process it
		while ((get_next_line(0, &command)))
		{
			command_dispatcher(env, command, 0);
			if (debug)
				debug_info(*(env->a), *(env->b), command);
			free(command);
		}

		// Push elements from A to B
		// while ((pop_el = pop(&a)) != NULL)
		// 	push(&b, pop_el);
		
		if (is_sorted(*(env->a), &srt_asc) && !(*(env->b)))
			ft_printf("%sOK%s\n", KGRN, KNRM);
		else
			ft_printf("%sKO%s\n", KRED, KNRM);
		// if (!debug)
		// {
			// Print values form A
			// ft_printf("\nStack A after processing commands:\n");
			// while (a)
			// {
			// 	ft_printf("%d ", a->val);
			// 	a = a->next;
			// }
			// ft_printf("\n");

		// 	// Print values from B
		// 	ft_printf("\nStack B after processing commands:\n");
		// 	while (b)
		// 	{
		// 		ft_printf("%d ", b->val);
		// 		b = b->next;
		// 	}
		// 	ft_printf("\n");
		// }
	}
	while (1);
	return (1);
}










