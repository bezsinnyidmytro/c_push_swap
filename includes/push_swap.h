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

typedef struct		s_env
{
	t_stack			**a;
	t_stack			**b;
	t_plist			**p_list;
	int				*sort;
	int				flag_mask;
	int				op_count;
}					t_env;

void				push(t_stack **s_top, t_stack *s_el);
t_stack				*pop(t_stack **s_top);
void				swap(t_stack **s_top);
void				rotate(t_stack **s_top);
void				rrotate(t_stack **s_top);

int					is_sign_or_digit(char ch);
void				debug_info(t_stack *a, t_stack *b, char *cmd,
								int flag_mask);
int					list_size(t_stack *stack);

int					*ps_flag_parse(int ac, char **av);
int					srt_asc(int a, int b);
int					is_sorted(t_stack *s_top, int (*f)());
void				error_call(char *message);
t_stack				*s_el_create(int val);

void				command_dispatcher(t_env *env, char *cmd, int announce);
t_env				*init_env(t_stack **a, t_stack **b, int flag_mask);

t_stack				*init_stack(int n_arg, char **av);

int					*list_to_arr_sort(t_stack *list);
int					is_sorted_tab(int *tab, int s, int e, int (*f)(int, int));

void				small_stack_sort(t_env *env);

t_plist				*plist_el_create(int val, char to);
void				plist_push(t_plist **s_top, t_plist *s_el);
void				plist_pop_free(t_plist **s_top);
void				plist_removeifa(t_plist **s_top);

void				sort_three(t_env *env, t_plist *pa, int numb);

void				process_perm_cases(t_env *env, int perma, int permb);

void				process_perma_zero(t_env *env, int permb);
void				process_perma_one(t_env *env, int permb);
void				process_perma_two(t_env *env, int permb);

int					has_lower_piv(t_stack *a, int piv);
int					has_higher_piv(t_stack *b, int piv);
void				common_triple_cmd(t_env *env);
void				run_triple_cmd(t_env *env, char stack, int mask);
int					ord_l(int el, int piv);

t_plist				*backpush_a(t_env *env, int piv);
t_plist				*backpush_b(t_env *env, int piv, t_plist **a_push,
								int *rot_ca);

void				stack_main_split(t_env *env);

#endif
