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

// CHECK FOR STACK A BEING SORTED AS IT IS at the start of the program
// CHECK FOR EMPTY STRING ARGUMENT
// CHECK FOR LENGTH AND USE ANOTHER SORT IF LESS THAN 6
// SEGFAULT ON 3 and less arguments

void		reserv()
{

}

int			main(int ac, char **av)
{
	t_stack		*a;
	int			i;
	int			flags_count;
	t_stack		*b;
	t_env		*env;
	//char		*command;
	//int			debug;
	//intmax_t	val;
	//int			arg_bound;

	//command = NULL;
	a = NULL;
	env = NULL;
	flags_count = ps_flag_parse(ac, av);
	b = NULL;
	i = ac - flags_count;
	//debug = 0;
	if (i > 1)
	{
		//arg_bound = 0;
		// if (ft_strcmp(av[1], "-d") == 0 && (debug = 1))
		// 	arg_bound++;
		// Push element to the A
		// while (--i > arg_bound)
		// {
		// 	if (!check_str(av[i], &is_sign_or_digit))
		// 		error_call("Bad INTEGER input.");
		// 	val = ft_atoimax(av[i]);
		// 	//ft_printf("Converted integer is %zi\n", val);
		// 	if (val < INT_MIN || val > INT_MAX)
		// 		error_call("Value is out of INTEGER range.");
		// 	push(&a, s_el_create(val));
		// }
		// if (a == NULL && b == NULL)					// set for UBUNTU
		// 	error_call("Memalloc error.");
		a = init_stack(i - 1, av + flags_count + 1);
		env = init_env(&a, &b);
		
		if (list_size(*(env->a)) < 7)
		{
			//ft_printf("Insert sort will be here :)\n");
			small_stack_sort(env);
		}
		else if (!is_sorted(*(env->a), &srt_asc))
			stack_main_split(env);

		//list_to_arr_sort(a);
		// fflush(stdout);

		// Read commnd on standard input and process it
		// while ((get_next_line(0, &command)))
		// {
		// 	command_dispatcher(&a, &b, command, 0);
		// 	if (debug)
		// 		debug_info(a, b, command);
		// }
		
		// if (is_sorted(a, &srt_asc) && !b)
		// 	ft_printf("%sOK\n", KGRN);
		// else
		// 	ft_printf("%sKO\n", KRED);
	}
	// while (1);
	return (1);
}