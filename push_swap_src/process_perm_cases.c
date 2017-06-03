/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_perm_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:26:57 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 16:26:58 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	process_perma_three(t_env *env, int permb)
{
	if (permb == 1 || permb == 4)
		command_dispatcher(env, "ss", 1);
	else
		command_dispatcher(env, "sa", 1);
	if (permb == 2 || permb == 4 || permb == 5)
		common_triple_cmd(env);
	if (permb == 2)
		command_dispatcher(env, "ss", 1);
	if (permb == 1 || permb == 0)
		run_triple_cmd(env, 'a', 7);
	if (permb != 2)
		command_dispatcher(env, "sa", 1);
}

static void	process_perma_four(t_env *env, int permb)
{
	if (permb == 1 || permb == 3)
		command_dispatcher(env, "ss", 1);
	else
		command_dispatcher(env, "sa", 1);
	if (permb == 2 || permb == 3 || permb == 5)
		common_triple_cmd(env);
	if (permb == 2 || permb == 3)
		command_dispatcher(env, "sb", 1);
	if (permb == 1 || permb == 0)
		run_triple_cmd(env, 'a', 7);
}

static void	process_perma_five(t_env *env, int permb)
{
	if (permb == 3 || permb == 4)
		command_dispatcher(env, "sb", 1);
	if (permb == 2 || permb == 3 || permb == 4)
		common_triple_cmd(env);
	if (permb == 2 || permb == 3)
		command_dispatcher(env, "sb", 1);
	if (permb == 0)
		run_triple_cmd(env, 'a', 7);
	if (permb == 1)
	{
		command_dispatcher(env, "ra", 1);
		command_dispatcher(env, "ss", 1);
		command_dispatcher(env, "rra", 1);
	}
}

static void	process_perm_equal(t_env *env, int perma)
{
	if (perma == 1)
		command_dispatcher(env, "ss", 1);
	else if (perma == 2)
	{
		common_triple_cmd(env);
		command_dispatcher(env, "ss", 1);
	}
	else if (perma == 3)
	{
		command_dispatcher(env, "ss", 1);
		common_triple_cmd(env);
		command_dispatcher(env, "ss", 1);
	}
	else if (perma == 4)
	{
		command_dispatcher(env, "ss", 1);
		common_triple_cmd(env);
	}
	else if (perma == 5)
		common_triple_cmd(env);
}

void		process_perm_cases(t_env *env, int perma, int permb)
{
	if (perma == permb && permb == 0)
		return ;
	if (perma == permb)
		process_perm_equal(env, perma);
	else
	{
		if (perma == 0)
			process_perma_zero(env, permb);
		if (perma == 1)
			process_perma_one(env, permb);
		if (perma == 2)
			process_perma_two(env, permb);
		if (perma == 3)
			process_perma_three(env, permb);
		if (perma == 4)
			process_perma_four(env, permb);
		if (perma == 5)
			process_perma_five(env, permb);
	}
}
