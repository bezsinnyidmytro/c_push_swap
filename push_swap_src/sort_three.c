/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:22:57 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 16:22:58 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_aperm_case(int a, int b, int c)
{
	int		perm_case;

	perm_case = 0;
	if (a > b && b < c && c > a)
		perm_case = 1;
	else if (a < b && b > c && c < a)
		perm_case = 2;
	else if (a > b && b > c && c < a)
		perm_case = 3;
	else if (a > b && b < c && c < a)
		perm_case = 4;
	else if (a < b && b > c && c > a)
		perm_case = 5;
	return (perm_case);
}

static int	get_bperm_case(int a, int b, int c)
{
	int		perm_case;

	perm_case = 0;
	if (a < b && b > c && c < a)
		perm_case = 1;
	else if (a > b && b < c && c > a)
		perm_case = 2;
	else if (a < b && b < c && c > a)
		perm_case = 3;
	else if (a < b && b > c && c > a)
		perm_case = 4;
	else if (a > b && b < c && c < a)
		perm_case = 5;
	return (perm_case);
}

static int	get_permcase_ab(t_env *env, char stack_name)
{
	if (stack_name == 'a')
	{
		return (get_aperm_case((*(env->a))->val,
			(*(env->a))->next->val, (*(env->a))->next->next->val));
	}
	else if (stack_name == 'b')
	{
		return (get_bperm_case((*(env->b))->val,
			(*(env->b))->next->val, (*(env->b))->next->next->val));
	}
	return (0);
}

void		sort_three(t_env *env, t_plist *pa, int numb)
{
	int		numa;
	int		perma;
	int		permb;

	numa = pa ? pa->count : list_size(*(env->a));
	numa = (numa > 3) ? 3 : numa;
	perma = 0;
	permb = 0;
	if (numa == 2)
	{
		if ((*(env->a))->val > (*(env->a))->next->val)
			perma = 1;
	}
	else if (numa == 3)
		perma = get_permcase_ab(env, 'a');
	if (numb == 2)
	{
		if ((*(env->b))->val < (*(env->b))->next->val)
			permb = 1;
	}
	else if (numb == 3)
		permb = get_permcase_ab(env, 'b');
	process_perm_cases(env, perma, permb);
	while (numb--)
		command_dispatcher(env, "pa", 1);
}
