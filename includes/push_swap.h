/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 13:44:13 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/05/11 13:44:14 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/src/libft.h"
# include <limits.h>

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[91m"
# define KGRN  "\x1B[92m"
# define KYEL  "\x1B[93m"
# define KBLU  "\x1B[94m"
# define KMAG  "\x1B[95m"
# define KCYN  "\x1B[96m"
# define KWHT  "\x1B[97m"

typedef struct		s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_plist
{
	int				count;
	char			to;
	int				b_is_rot;
	struct s_plist	*next;
}					t_plist;

typedef struct 		s_env
{
	t_stack			**a;
	t_stack			**b;
	t_plist			**p_list;
	int				*sort;
	int				b_is_rot;
}					t_env;

int 				srt_asc(int a, int b);
int 				srt_desc(int a, int b);

int 				is_sorted(t_stack *s_top, int (*f)());
void				error_call(char *message);
t_stack				*s_el_create(int val);
void				push(t_stack **s_top, t_stack *s_el);
t_stack				*pop(t_stack **s_top);
void				swap(t_stack **s_top);
void				rotate(t_stack **s_top);
void				rrotate(t_stack **s_top);
void				command_dispatcher(t_env *env, char *cmd, int announce);
t_stack				*init_stack(int n_arg, char **av);
t_env				*init_env(t_stack **a, t_stack **b);
int					ps_flag_parse(int ac, char **av);
int					list_size(t_stack *stack);
void				small_stack_sort(t_env *env);

int					*list_to_arr_sort(t_stack *list);

void				debug_info(t_stack const *a, t_stack const *b, char *cmd);

void				stack_main_split(t_env *env);

int					rot_or_rrot(t_stack *stack, int piv, int (*ord)(), int (*has)());

#endif