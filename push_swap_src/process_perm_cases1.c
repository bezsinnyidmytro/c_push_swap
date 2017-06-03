/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_perm_cases1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:29:32 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 16:29:33 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		process_perma_zero(t_env *env, int permb)
{
	if (permb == 1 || permb == 3 || permb == 4)
		command_dispatcher(env, "sb", 1);
	if (permb > 1)
		run_triple_cmd(env, 'b', 7);
	if (permb == 2 || permb == 3)
		command_dispatcher(env, "sb", 1);
}

void		process_perma_one(t_env *env, int permb)
{
	if (permb == 3 || permb == 4)
		command_dispatcher(env, "ss", 1);
	if (permb == 2 || permb == 3 || permb == 4)
		run_triple_cmd(env, 'b', 7);
	if (permb == 2)
		command_dispatcher(env, "ss", 1);
	if (permb == 3)
		command_dispatcher(env, "sb", 1);
	if (permb == 0)
		command_dispatcher(env, "sa", 1);
	if (permb == 5)
	{
		command_dispatcher(env, "rb", 1);
		command_dispatcher(env, "ss", 1);
		command_dispatcher(env, "rrb", 1);
	}
}

void		process_perma_two(t_env *env, int permb)
{
	if (permb == 3 || permb == 4)
		command_dispatcher(env, "sb", 1);
	if (permb == 3 || permb == 4 || permb == 5)
		common_triple_cmd(env);
	if (permb == 3)
		command_dispatcher(env, "ss", 1);
	if (permb == 1 || permb == 0)
		run_triple_cmd(env, 'a', 7);
	if (permb == 1)
		command_dispatcher(env, "ss", 1);
	if (permb == 5 || permb == 4 || permb == 0)
		command_dispatcher(env, "sa", 1);
}
