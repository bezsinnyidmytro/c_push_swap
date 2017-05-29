 #include "../includes/push_swap.h"

void		reserve()
{

}

char	*ft_dstrjoin(char *s1, char *s2, int ff1, int ff2)
{
	size_t	len;
	char	*str_new;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str_new = ft_strnew(len);
	if (!str_new)
		return (NULL);
	str_new = ft_strcat(str_new, s1);
	str_new = ft_strcat(str_new, s2);
	if (ff1)
		free(s1);
	if (ff2)
		free(s2);
	return (str_new);
}

// void	command_dispatcher2(t_stack **a, t_stack **b, char *cmd, int announce, char **cmd_full_str)
// {
// 	command_dispatcher(env, cmd, announce);
// 	cmd = ft_dstrjoin(cmd, "\n", 0, 0);																						// huge troubles with free
// 	*cmd_full_str = ft_dstrjoin(*cmd_full_str, cmd, 0, 0);
// }

t_plist		*plist_el_create(int val, char to)
{
	t_plist	*el;

	el = (t_plist *)malloc(sizeof(t_plist));
	el->count = val;
	el->to = to;
	el->next = NULL;
	return (el);
}

void		plist_push(t_plist **s_top, t_plist *s_el)
{
	t_plist	*old_top;

	if (s_el)
	{
		old_top = *s_top;
		*s_top = s_el;
		(*s_top)->next = old_top;
	}
}

t_plist		*plist_pop(t_plist **s_top)
{
	t_plist	*res;

	res = NULL;
	if (*s_top)
	{
		res = *s_top;
		*s_top = (*s_top)->next;
	}
	return (res);
}

void		plist_removeifa(t_plist **s_top)
{
	//t_plist	*prev;

	if ((*s_top)->next)
		plist_removeifa(&((*s_top)->next));
	if ((*s_top)->to == 'A')
		(*s_top) = (*s_top)->next;
}

int			has_lower_piv(t_stack *a, int piv)
{
	while (a)
	{
		if (a->val < piv)
			return (1);
		a = a->next;
	}
	return (0);
}

int			get_aperm_case(int a, int b, int c)
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

int			get_bperm_case(int a, int b, int c)
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

void		ft_strreplacechr(char *str, char find, char replace)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str == find)
			*str = replace;
		str++;
	}
}

char		**get_clist(int perm_case, char stack_heading)
{
	char	*cstr;

	cstr = NULL;
	if (perm_case == 1)
		cstr = ft_strdup("sa");
	else if (perm_case == 2)
		cstr = ft_strdup("ra sa rra sa");
	else if (perm_case == 3)
		cstr = ft_strdup("sa ra sa rra sa");
	else if (perm_case == 4)
		cstr = ft_strdup("sa ra sa rra");
	else if (perm_case == 5)
		cstr = ft_strdup("ra sa rra");
	if (stack_heading == 'b')
		ft_strreplacechr(cstr, 'a', 'b');
	return (ft_strsplit(cstr, ' '));
}

int			is_stackable_cmd(char *cmd_a, char *cmd_b)
{
	int		alen;
	int		blen;
	int		i;

	alen = ft_strlen(cmd_a);
	blen = ft_strlen(cmd_b);
	if (alen == blen)
	{
		i = -1;
		while (++i < alen - 1)
		{
			if (cmd_a[i] != cmd_b[i])
				return (0);
		}
		return (1);
	}
	return (0);
}

int			has_stackable_cmd(char *cmd, char **iter)
{
	while (iter && *iter)
	{
		if (is_stackable_cmd(cmd, *iter))
			return (1);
		iter++;
	}
	return (0);
}

void		run_common_cmd(t_env *env, char *cmd)
{
	int		len;

	len = ft_strlen(cmd);
	cmd[len - 1] = (cmd[len - 1] == 'a') ? 's' : 'r';
	command_dispatcher(env, cmd, 1);
}

void		common_triple_cmd(t_env *env)
{
	command_dispatcher(env, "rr", 1);
	command_dispatcher(env, "ss", 1);
	command_dispatcher(env, "rrr", 1);
}

void		run_triple_cmd(t_env *env, char stack)
{
	if (stack == 'a')
	{
		command_dispatcher(env, "ra", 1);
		command_dispatcher(env, "sa", 1);
		command_dispatcher(env, "rra", 1);
	}
	else if (stack == 'b')
	{
		command_dispatcher(env, "rb", 1);
		command_dispatcher(env, "sb", 1);
		command_dispatcher(env, "rrb", 1);
	}
}

void		process_perm_cases(t_env *env, int permA, int permB)
{
	// t_stack		*a_iter;
	// t_stack		*b_iter;
	// int			i;

	// printf("Permutation A: %i, B: %i\n", permA, permB);
	// i = 0;
	// a_iter = *a;
	// b_iter = *b;

	// printf("Stack A:\n");
	// while (i < 3 && a_iter)
	// {
	// 	printf("%5i", a_iter->val);
	// 	a_iter = a_iter->next;
	// }	

	// i = 0;
	// printf("\n\nStack B:\n");
	// while (i < 3 && b_iter)
	// {
	// 	printf("%5i", b_iter->val);
	// 	b_iter = b_iter->next;
	// }
	// printf("\n");



	if (permA == permB && permB == 0)
		return ;

	if (permA == permB)
	{
		if (permA == 1)
			command_dispatcher(env, "ss", 1);
		else if (permA == 2)
		{
			common_triple_cmd(env);
			command_dispatcher(env, "ss", 1);
		}
		else if (permA == 3)
		{
			command_dispatcher(env, "ss", 1);
			common_triple_cmd(env);
			command_dispatcher(env, "ss", 1);
		}
		else if (permA == 4)
		{
			command_dispatcher(env, "ss", 1);
			common_triple_cmd(env);
		}
		else if (permA == 5)
			common_triple_cmd(env);
	}
	else
	{
		if (permA == 0)
		{
			if (permB == 1 || permB == 3 || permB == 4)
				command_dispatcher(env, "sb", 1);
			if (permB > 1)
				run_triple_cmd(env, 'b');
			if (permB == 2 || permB == 3)
				command_dispatcher(env, "sb", 1);


			// if (permB == 1)
			// 	command_dispatcher(env, "sb", 1);
			// else if (permB == 2)
			// {
			// 	run_triple_cmd(env, 'b');
			// 	command_dispatcher(env, "sb", 1);
			// }
			// else if (permB == 3)
			// {
			// 	command_dispatcher(env, "sb", 1);
			// 	run_triple_cmd(env, 'b');
			// 	command_dispatcher(env, "sb", 1);
			// }
			// else if (permB == 4)
			// {
			// 	command_dispatcher(env, "sb", 1);
			// 	run_triple_cmd(env, 'b');
			// }
			// else if (permB == 5)
			// 	run_triple_cmd(env, 'b');
		}

		if (permA == 1)					// no common for 1-5
		{
			if (permB == 3 || permB == 4)
				command_dispatcher(env, "ss", 1);
			if (permB == 2 || permB == 3 || permB == 4 || permB == 5)
				run_triple_cmd(env, 'b');
			if (permB == 2)
				command_dispatcher(env, "ss", 1);
			if (permB == 3)
				command_dispatcher(env, "sb", 1);
			if (permB == 5 || permB == 0)
				command_dispatcher(env, "sa", 1);

			// if (permB == 0)
			// 	command_dispatcher(env, "sa", 1);
			// else if (permB == 2)
			// {
			// 	run_triple_cmd(env, 'b');
			// 	command_dispatcher(env, "ss", 1);
			// }
			// else if (permB == 3)
			// {
			// 	command_dispatcher(env, "ss", 1);
			// 	run_triple_cmd(env, 'b');
			// 	command_dispatcher(env, "sb", 1);
			// }
			// else if (permB == 4)
			// {
			// 	command_dispatcher(env, "ss", 1);
			// 	run_triple_cmd(env, 'b');
			// }
			// else if (permB == 5)
			// {
			// 	run_triple_cmd(env, 'b');
			// 	command_dispatcher(env, "sa", 1);
			// }
		}

		if (permA == 2)
		{
			if (permB == 3 || permB == 4)
				command_dispatcher(env, "sb", 1);
			if (permB == 3 || permB == 4 || permB == 5)
				common_triple_cmd(env);
			if (permB == 3)
				command_dispatcher(env, "ss", 1);
			if (permB == 1 || permB == 0)
				run_triple_cmd(env, 'a');
			if (permB == 1)
				command_dispatcher(env, "ss", 1);
			if (permB == 5 || permB == 4 || permB == 0)
				command_dispatcher(env, "sa", 1);

			// if (permB == 0)
			// {
			// 	run_triple_cmd(env, 'a');
			// 	command_dispatcher(env, "sa", 1);
			// }
			// else if (permB == 1)
			// {
			// 	run_triple_cmd(env, 'a');
			// 	command_dispatcher(env, "ss", 1);
			// }
			// else if (permB == 3)
			// {
			// 	command_dispatcher(env, "sb", 1);
			// 	common_triple_cmd(env);
			// 	command_dispatcher(env, "ss", 1);
			// }
			// else if (permB == 4)
			// {
			// 	command_dispatcher(env, "sb", 1);
			// 	common_triple_cmd(env);
			// 	command_dispatcher(env, "sa", 1);
			// }
			// else if (permB == 5)
			// {
			// 	common_triple_cmd(env);
			// 	command_dispatcher(env, "sa", 1);
			// }
		}

		if (permA == 3)
		{
			if (permB == 1 || permB == 4)
				command_dispatcher(env, "ss", 1);
			else
				command_dispatcher(env, "sa", 1);
			if (permB == 2 || permB == 4 || permB == 5)
				common_triple_cmd(env);
			if (permB == 2)
				command_dispatcher(env, "ss", 1);
			if (permB == 1 || permB == 0)
				run_triple_cmd(env, 'a');
			if (permB != 2)
				command_dispatcher(env, "sa", 1);

			// if (permB == 0)
			// {
			// 	command_dispatcher(env, "sa", 1);
			// 	run_triple_cmd(env, 'a');
			// 	command_dispatcher(env, "sa", 1);
			// }
			// else if (permB == 1)
			// {
			// 	command_dispatcher(env, "ss", 1);
			// 	run_triple_cmd(env, 'a');
			// 	command_dispatcher(env, "sa", 1);
			// }
			// else if (permB == 2)
			// {
			// 	command_dispatcher(env, "sa", 1);
			// 	common_triple_cmd(env);
			// 	command_dispatcher(env, "ss", 1);
			// }
			// else if (permB == 4)
			// {
			// 	command_dispatcher(env, "ss", 1);
			// 	common_triple_cmd(env);
			// 	command_dispatcher(env, "sa", 1);
			// }
			// else if (permB == 5)
			// {
			// 	command_dispatcher(env, "sa", 1);
			// 	common_triple_cmd(env);
			// 	command_dispatcher(env, "sa", 1);
			// }
		}

		if (permA == 4)
		{
			if (permB == 1 || permB == 3)
				command_dispatcher(env, "ss", 1);
			else
				command_dispatcher(env, "sa", 1);
			if (permB == 2 || permB == 3 || permB == 5)
				common_triple_cmd(env);
			if (permB == 2 || permB == 3)
				command_dispatcher(env, "sb", 1);
			if (permB == 1 || permB == 0)
				run_triple_cmd(env, 'a');

			// if (permB == 0)
			// {
			// 	command_dispatcher(env, "sa", 1);
			// 	run_triple_cmd(env, 'a');
			// }
			// else if (permB == 1)
			// {
			// 	command_dispatcher(env, "ss", 1);
			// 	run_triple_cmd(env, 'a');
			// }
			// else if (permB == 2)
			// {
			// 	command_dispatcher(env, "sa", 1);
			// 	common_triple_cmd(env);
			// 	command_dispatcher(env, "sb", 1);
			// }
			// else if (permB == 3)
			// {
			// 	command_dispatcher(env, "ss", 1);
			// 	common_triple_cmd(env);
			// 	command_dispatcher(env, "sb", 1);
			// }
			// else if (permB == 5)
			// {
			// 	command_dispatcher(env, "sa", 1);
			// 	common_triple_cmd(env);
			// }
		}

		if (permA == 5)
		{
			if (permB == 1 || permB == 3 || permB == 4)
				command_dispatcher(env, "sb", 1);
			if (permB == 2 || permB == 3 || permB == 4)
				common_triple_cmd(env);
			if (permB == 2 || permB == 3)
				command_dispatcher(env, "sb", 1);
			if (permB == 1 || permB == 0)
				run_triple_cmd(env, 'a');

			// if (permB == 0)
			// {
			// 	run_triple_cmd(env, 'a');
			// }
			// else if (permB == 1)
			// {
			// 	command_dispatcher(env, "sb", 1);
			// 	run_triple_cmd(env, 'a');
			// }
			// else if (permB == 2)
			// {
			// 	common_triple_cmd(env);
			// 	command_dispatcher(env, "sb", 1);
			// }
			// else if (permB == 3)
			// {
			// 	command_dispatcher(env, "sb", 1);
			// 	common_triple_cmd(env);
			// 	command_dispatcher(env, "sb", 1);
			// }
			// else if (permB == 4)
			// {
			// 	command_dispatcher(env, "sb", 1);
			// 	common_triple_cmd(env);
			// }
		}
	}


	// char	**clist_a;
	// char	**clist_b;
	// //char	**iter_a;
	// //char	**iter_b;
	// char	**iter;

	// clist_a = get_clist(permA, 'a');
	// clist_b = get_clist(permB, 'b');

	// //iter_a = clist_a;
	// //iter_b = clist_b;

	
	// iter = clist_a;
	// while (iter && *iter)
	// {
	// 	command_dispatcher(env, *iter, 1);
	// 	iter++;
	// }
	// iter = clist_b;
	// while (iter && *iter)
	// {
	// 	command_dispatcher(env, *iter, 1);
	// 	iter++;
	// }
}

void		sort_three(t_env *env, t_plist *pa, int numb)
{
	int		numa;
	int		permA;
	int		permB;

	numa = pa ? pa->count : list_size(*(env->a));
	numa = (numa > 3) ? 3 : numa;

	// stupid sort
	permA = 0;
	permB = 0;
	if (numa == 2)
	{
		if ((*(env->a))->val > (*(env->a))->next->val)
			permA = 1;
	}
	else if (numa == 3)
		permA = get_aperm_case((*(env->a))->val, (*(env->a))->next->val, (*(env->a))->next->next->val);

	if (numb == 2)
	{
		if ((*(env->b))->val < (*(env->b))->next->val)
			permB = 1;
	}
	else if (numb == 3)
		permB = get_bperm_case((*(env->b))->val, (*(env->b))->next->val, (*(env->b))->next->next->val);
	//printf("Permutation caseA: %i. caseB: %i\n.", permA, permB);

	process_perm_cases(env, permA, permB);

	while (numb--)
	{
		//printf("Pushed to A: %i\n", (*b)->val);
		//*cmd_str = ft_dstrjoin(*cmd_str, "pa\n", 1, 0);
		command_dispatcher(env, "pa", 1);
	}
}

t_plist		*backpush_a(t_env *env)
{
	int		i;

	i = (*(env->p_list))->count;
	(*(env->p_list))->to = 'A';
	while (i--)
		command_dispatcher(env, "pa", 1);
	//printf("Pushed back to A: %i\n", (*p_list)->count);
	return (*(env->p_list));
}

t_plist		*backpush_b(t_env *env, int piv, t_plist **a_push)
{
	int		rot_counter;
	int		pushed;

	pushed = 0;
	rot_counter = 0;
	while (has_lower_piv(*(env->a), piv))
	{
		while ((*(env->a))->val >= piv)
		{
			command_dispatcher(env, "ra", 1);
			rot_counter++;
		}
		command_dispatcher(env, "pb", 1);
		pushed++;
	}
	(*a_push)->count -= pushed;
	while (rot_counter--)
		command_dispatcher(env, "rra", 1);
	//printf("Pushed bakc to B: %i\n", pushed);
	return (plist_el_create(pushed, 'B'));
}

void		stacks_sort(t_env *env)
{
	t_plist	*a_push;	// for the nearest push to A
	int		piv;
	int		full_size;
	int		sort_size;
	int		numb;

	full_size = list_size(*(env->a)) + list_size(*(env->b));
	while (*(env->p_list))
	{
		sort_size = list_size(*(env->a));
		a_push = backpush_a(env);
		while (a_push->count > 3)
		{
			piv = env->sort[(2 * full_size - sort_size - list_size(*(env->a))) / 2];
			//printf("The pivot is: %i\n", piv);
			plist_push(env->p_list, backpush_b(env, piv, &a_push));
		}

		numb = ((*(env->p_list))->to == 'B') ? (*(env->p_list))->count : 0;
		sort_three(env, a_push, numb);
		plist_removeifa(env->p_list);
		if (numb != 0)
			plist_pop(env->p_list);				// need to free it ?
		// if (*(p_list)->count <= 3 &&
		// 	(!(a_push = find_plist_a(*p_list)) || a_push->count <= 3))		// how to find out how many elements you need to sort
		// {
		// 	sort_three(a, b, a_push, p_list->count);
		// }

	}
}

// void		cmd_str_opt(char **cmd_full_str)
// {
// 	char	*iter;
// 	char

// 	iter = *cmd_full_str;
// 	while ()
// }

void		stack_main_split(t_env *env)
{
	//int		*s_arr;
	int		stack_len;
	t_plist *push_list;
	//int		i;
	int		piv;
	int		pushed_total;
	int		pushed;
	//t_stack	*iter;
	//t_plist	*tp_iter;
	int		numb;
	//char	*cmd_full_str;

	// full cmd string
	//cmd_full_str = ft_strnew(0);

	push_list = NULL;
	stack_len = list_size(*(env->a));
	env->sort = list_to_arr_sort(*(env->a));

	pushed_total = 0;

	//printf("Commands for main split:\n");

	while (list_size(*(env->a)) > 3)
	{
		pushed = 0;
		piv = env->sort[(stack_len + pushed_total) / 2];
		// printf("Piv is: %i\n", piv);
		// sleep(1);
		while (has_lower_piv(*(env->a), piv))
		{
			while ((*(env->a))->val >= piv)
			{
				command_dispatcher(env, "ra", 1); //rotate(a);
			}
			command_dispatcher(env, "pb", 1); //push(b, pop(a));
			pushed++;
		}
		plist_push(&push_list, plist_el_create(pushed, 'B'));
		pushed_total += pushed;
	}
	// i = -1;
	// while (++i < stack_len)
	// 	printf("%*i", ft_nbrlen(s_arr[i]) + 3, s_arr[i]);
	// printf("\n");
	// if (!(*b))
	// 	printf("Stack B is empty.\n");


	// printf("Stacks after push operations\n");
	// debug_info(*a, *b, NULL);
	// tp_iter = push_list;
	// printf("Push list after push operations:\n");
	// while (tp_iter)
	// {
	// 	printf("Pushed: %i, to %c.\n", tp_iter->count, tp_iter->to);
	// 	tp_iter = tp_iter->next;
	// }

	//printf("Commands for stack-sort:\n");

	// Sort start
	numb = push_list->count > 3 ? 0 : push_list->count;
	//sort_three(a, b, NULL, numb, &cmd_full_str);
	sort_three(env, NULL, numb);
	if (numb != 0)
		plist_pop(&push_list);			// should use free here probably
	// tp_iter = push_list;
	// printf("Push list after first sort:\n");
	// while (tp_iter)
	// {
	// 	printf("Pushed: %i, to %c.\n", tp_iter->count, tp_iter->to);
	// 	tp_iter = tp_iter->next;
	// }

	// // After sort or something that looks like sort :)
	// printf("Stacks after first sort operations\n");
	// debug_info(*a, *b, NULL);
	// fflush(stdout);

	//stacks_sort(a, b, &push_list, s_arr, &cmd_full_str);
	env->p_list = &push_list;

	stacks_sort(env);
	

	//printf("%s", cmd_full_str);
	// sort_three(a, b, NULL, push_list->count);		// should be called from stacks_sort()
	// plist_pop(&push_list);							// need to free and use only with IF
	// sort_three(a, b, NULL, push_list->count);
	// plist_pop(&push_list);							// need to free and use only with IF

	// After sort or something that looks like sort :)
	// printf("Stacks after sort operations\n");
	// debug_info(*a, *b, NULL);

	// // Test last pivot
	// piv = s_arr[(2 * stack_len - 2 * list_size(*a) - push_list->count) / 2];
	// //piv = (2 * stack_len - 2 * list_size(*a) - push_list->count) / 2;
	// printf("\n\nThe last pivot is: %i.\n", piv);

	// printf("Push list:\n");
	// while (push_list)
	// {
	// 	printf("Pushed: %i, to %c.\n", push_list->count, push_list->to);
	// 	push_list = push_list->next;
	// }	
}