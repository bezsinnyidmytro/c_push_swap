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

void		reserv()
{

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

int			main(int ac, char **av)
{
	t_stack		*a;
	int			i;
	t_stack		*b;
	char		*command;
	int			debug;
	intmax_t	val;
	int			arg_bound;

	command = NULL;
	a = NULL;
	b = NULL;
	i = ac;
	debug = 0;
	if (i > 1)
	{
		arg_bound = 0;
		// if (ft_strcmp(av[1], "-d") == 0 && (debug = 1))
		// 	arg_bound++;
		// Push element to the A
		while (--i > arg_bound)
		{
			if (!check_str(av[i], &is_sign_or_digit))
				error_call("Bad INTEGER input.");
			val = ft_atoimax(av[i]);
			//printf("Converted integer is %zi\n", val);
			if (val < INT_MIN || val > INT_MAX)
				error_call("Value is out of INTEGER range.");
			push(&a, s_el_create(val));
		}
		
		// fflush(stdout);

		// Read commnd on standard input and process it
		// while ((get_next_line(0, &command)))
		// {
		// 	command_dispatcher(&a, &b, command, 0);
		// 	if (debug)
		// 		debug_info(a, b, command);
		// }
		
		// if (is_sorted(a, &srt_asc) && !b)
		// 	printf("%sOK\n", KGRN);
		// else
		// 	printf("%sKO\n", KRED);
	}

	return (1);
}