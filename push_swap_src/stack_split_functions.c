 #include "../includes/push_swap.h"

t_stack		*last_in_stack(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s);
}

t_stack		*prelast_in_stack(t_stack *s)
{
	while (s->next->next)
		s = s->next;
	return (s);
}

int 		min_val_pos(t_stack *ss)
{
	int		min;
	int		i;
	int		min_idx;

	min = ss->val;
	i = 1;
	min_idx = i;
	while (ss)
	{
		if (ss->val < min)
		{
			min = ss->val;
			min_idx = i;
		}
		i++;
		ss = ss->next;
	}
	return (min_idx);
}

void		small_stack_sort(t_env *env)
{
	int			min_ord;

	// if (env)
	// 	ft_printf("IDITE NAHYI EBANYE STACKi\n");

	while (list_size(*(env->a)) > 3)
	{
		min_ord = min_val_pos(*(env->a));
		//ft_printf("Min pos: %i\n", min_ord);
		if (min_ord <= list_size(*(env->a)) / 2)
			while (--min_ord)
				command_dispatcher(env, "ra", 1);
		else
			while (min_ord++ <= list_size(*(env->a)))
				command_dispatcher(env, "rra", 1);
		command_dispatcher(env, "pb", 1);
	}
	if (list_size(*(env->a)) > 1)
		if ((*(env->a))->val > (*(env->a))->next->val)
			command_dispatcher(env, "sa", 1);
	if (list_size(*(env->a)) == 3)
	{
		if ((*(env->a))->next->next->val < (*(env->a))->next->val)
			command_dispatcher(env, "rra", 1);
		if ((*(env->a))->val > (*(env->a))->next->val)
			command_dispatcher(env, "sa", 1);
	}
	while (list_size(*(env->b)) > 0)
		command_dispatcher(env, "pa", 1);
}

t_plist		*plist_el_create(int val, char to)
{
	t_plist	*el;

	el = (t_plist *)malloc(sizeof(t_plist));
	el->count = val;
	el->to = to;
	el->b_is_rot = 0;
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

void		plist_pop_free(t_plist **s_top)
{
	t_plist	*to_free;

	to_free = NULL;
	if (*s_top)
	{
		to_free = *s_top;
		*s_top = (*s_top)->next;
	}
	to_free->next = NULL;
	free(to_free);
}

void		plist_removeifa(t_plist **s_top)
{
	t_plist	*to_free;

	if ((*s_top)->next)
		plist_removeifa(&((*s_top)->next));
	if ((*s_top)->to == 'A')
	{
		to_free = (*s_top);
		(*s_top) = (*s_top)->next;
		to_free->next = NULL;
		free(to_free);
	}
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

int			has_higher_piv(t_stack *b, int piv)
{
	while (b)
	{
		if (b->val >= piv)
			return (1);
		b = b->next;
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

void		common_triple_cmd(t_env *env)
{
	command_dispatcher(env, "rr", 1);
	command_dispatcher(env, "ss", 1);
	command_dispatcher(env, "rrr", 1);
}

void		run_triple_cmd(t_env *env, char stack, int mask)
{
	if (stack == 'a')
	{
		if ((mask & 1) == 1)
			command_dispatcher(env, "ra", 1);
		if ((mask & 2) == 2)
			command_dispatcher(env, "sa", 1);
		if ((mask & 4) == 4)
			command_dispatcher(env, "rra", 1);
	}
	else if (stack == 'b')
	{
		if ((mask & 1) == 1)
			command_dispatcher(env, "rb", 1);
		if ((mask & 2) == 2)
			command_dispatcher(env, "sb", 1);
		if ((mask & 4) == 4)
			command_dispatcher(env, "rrb", 1);
	}
}

void		process_perm_cases(t_env *env, int permA, int permB)
{
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
				run_triple_cmd(env, 'b', 7);
			if (permB == 2 || permB == 3)
				command_dispatcher(env, "sb", 1);
		}

		if (permA == 1)
		{
			if (permB == 3 || permB == 4)
				command_dispatcher(env, "ss", 1);
			if (permB == 2 || permB == 3 || permB == 4)
				run_triple_cmd(env, 'b', 7);
			if (permB == 2)
				command_dispatcher(env, "ss", 1);
			if (permB == 3)
				command_dispatcher(env, "sb", 1);
			if (permB == 0)
				command_dispatcher(env, "sa", 1);
			if (permB == 5)
			{
				command_dispatcher(env, "rb", 1);
				command_dispatcher(env, "ss", 1);
				command_dispatcher(env, "rrb", 1);
			}
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
				run_triple_cmd(env, 'a', 7);
			if (permB == 1)
				command_dispatcher(env, "ss", 1);
			if (permB == 5 || permB == 4 || permB == 0)
				command_dispatcher(env, "sa", 1);
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
				run_triple_cmd(env, 'a', 7);
			if (permB != 2)
				command_dispatcher(env, "sa", 1);
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
				run_triple_cmd(env, 'a', 7);
		}

		if (permA == 5)
		{
			if (permB == 3 || permB == 4)
				command_dispatcher(env, "sb", 1);
			if (permB == 2 || permB == 3 || permB == 4)
				common_triple_cmd(env);
			if (permB == 2 || permB == 3)
				command_dispatcher(env, "sb", 1);
			if (permB == 0)
				run_triple_cmd(env, 'a', 7);
			if (permB == 1)
			{
				command_dispatcher(env, "ra", 1);
				command_dispatcher(env, "ss", 1);
				command_dispatcher(env, "rra", 1);
			}
		}
	}
}

void		sort_three(t_env *env, t_plist *pa, int numb)
{
	int		numa;
	int		permA;
	int		permB;

	//ft_printf("Sort three\n");
	// if (!pa)
	// 	ft_printf("THERE IS NO POINTER TO PA\n");

	numa = pa ? pa->count : list_size(*(env->a));
	numa = (numa > 3) ? 3 : numa;
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

	process_perm_cases(env, permA, permB);

	while (numb--)
		command_dispatcher(env, "pa", 1);
}

// for rot_or_rrot
int			ord_l(int el, int piv)
{
	return (el < piv);
}

int			ord_h(int el, int piv)
{
	return (el >= piv);
}

int			rot_or_rrot(t_stack *stack, int piv, int (*ord)(), int (*has)())
{
	// Predefined that stack has at least one value to push
	int		first;
	int		last;
	int		stack_size;

	// debug_info(stack, NULL, "test");
	// ft_printf("Pivot is: %i\n", piv);

	stack_size = list_size(stack);
	first = 1;
	while (1)
	{
		if ((*ord)(stack->val, piv))
			break ;
		first++;
		stack = stack->next;
	}
	last = first;
	stack = stack->next;
	while ((*has)(stack, piv))
	{
		last++;
		stack = stack->next;
	}
	if (first > stack_size / 2 && last > stack_size / 2)
		return (0);
	return (1);
}

t_plist		*backpush_a(t_env *env, int piv)
{
	int		pushed;
	int		i;
	int		plist_len;

	pushed = 0;
	i = 0;
	plist_len = (*(env->p_list))->count;
	if ((*(env->p_list))->b_is_rot == 1)
		plist_len += (plist_len + 1) / 2;

	// ft_printf("Backpush A:\n");
	// ft_printf("The plist->count: %i\n", (*(env->p_list))->count);
	// ft_printf("The plist_len for iter: %i\n", plist_len);
	// ft_printf("The is_rot: %i\n", (*(env->p_list))->b_is_rot);

	// ft_printf("The piv is: %i\n", piv);
	// debug_info(*(env->a), *(env->b), "test");

	while (i < plist_len)
	{
		while (has_higher_piv(*(env->b), piv) && (*(env->b))->val < piv)
		{
			if (!((*(env->p_list))->b_is_rot))
				command_dispatcher(env, "rb", 1);
			else
				command_dispatcher(env, "rrb", 1);
			i++;
		}
		command_dispatcher(env, "pa", 1);
		pushed++;
		i++;
		if (!has_higher_piv(*(env->b), piv) && i < plist_len)
		{
			while (i < plist_len)
			{
				if (!((*(env->p_list))->b_is_rot))
					command_dispatcher(env, "rb", 1);
				else
					command_dispatcher(env, "rrb", 1);
				i++;
			}
		}
	}

	(*(env->p_list))->b_is_rot = (*(env->p_list))->b_is_rot ? 0 : 1;

	
	(*(env->p_list))->count -= pushed;

	// ft_printf("The pushed: %i\n", pushed);
	// ft_printf("The new plist->count %i\n", (*(env->p_list))->count);

	i = plist_len - pushed;
	if ((*(env->p_list))->count <= 3)
	{
		//ft_printf("Enter the if statement with i = %i\n", i);
		// restore stack b
		if ((*(env->p_list))->b_is_rot)
		{
			//ft_printf("Before rrb loop with i = %i\n", i);
			while (i--)
				command_dispatcher(env, "rrb", 1);
			(*(env->p_list))->b_is_rot = 0;
		}
	}

	plist_push(env->p_list, plist_el_create(pushed, 'A'));
	return (*(env->p_list));
}

t_plist		*backpush_b(t_env *env, int piv, t_plist **a_push, int *rot_ca)
{
	int		pushed;
	int		r_or_rr;

	//ft_printf("Backpush B:\n");

	pushed = 0;
	while (has_lower_piv(*(env->a), piv))
	{

		r_or_rr = rot_or_rrot(*(env->a), piv, &ord_l, &has_lower_piv);
		
		while ((*(env->a))->val >= piv)
		{
			if (r_or_rr)
			{
				command_dispatcher(env, "ra", 1);
				(*rot_ca)++;
			}
			else
			{
				command_dispatcher(env, "rra", 1);
				(*rot_ca)--;
			}
		}
		command_dispatcher(env, "pb", 1);
		pushed++;
	}
	(*a_push)->count -= pushed;
	return (plist_el_create(pushed, 'B'));
}

void		restore_a(t_env *env, int *rot_ca)
{
	if (*rot_ca > 0)
	{
		//ft_printf("Restore A commands: \n");
		while ((*rot_ca)--)
			command_dispatcher(env, "rra", 1);
	}
	else if (*rot_ca < 0)
	{
		//ft_printf("Restore A commands: \n");
		while ((*rot_ca)++)
			command_dispatcher(env, "ra", 1);
	}
	*rot_ca = 0;
}

void		stacks_sort(t_env *env)
{
	t_plist	*a_push;	// for the nearest push to A
	int		piv;
	int		piv2;
	int		full_size;
	int		sort_size;
	int		numb;
	int		rot_ca;
	//int		rot_cb;

	rot_ca = 0;
	//rot_cb = 0;

	full_size = list_size(*(env->a)) + list_size(*(env->b));

	while (*(env->p_list))
	{
		sort_size = list_size(*(env->a));
		
		piv2 = env->sort[(2 * full_size - 2 * sort_size - (*(env->p_list))->count) / 2];

		if ((*(env->p_list))->to == 'B' && (*(env->p_list))->count > 3)			// probably can delete if-part->to == 'B'
			a_push = backpush_a(env, piv2);
		else if ((*(env->p_list))->to == 'B' && (*(env->p_list))->count <= 3)	// add for UBUNTU
			a_push = NULL;

		while (a_push && a_push->count > 3)
		{
			piv = env->sort[(2 * full_size - sort_size - list_size(*(env->a))) / 2];
			plist_push(env->p_list, backpush_b(env, piv, &a_push, &rot_ca));
		}

		numb = ((*(env->p_list))->to == 'B') ? (*(env->p_list))->count : (*(env->p_list))->next->count;

		restore_a(env, &rot_ca);

		sort_three(env, a_push, numb);
		plist_removeifa(env->p_list);
		if (numb != 0)
			plist_pop_free(env->p_list);				// need to free it ?
	}
}

void		stack_main_split(t_env *env)
{
	int		stack_len;
	t_plist *push_list;
	int		piv;
	int		pushed_total;
	int		pushed;
	int		numb;
	//int		path;

	push_list = NULL;
	stack_len = list_size(*(env->a));
	env->sort = list_to_arr_sort(*(env->a));

	pushed_total = 0;

	//ft_printf("Commands for main split:\n");

	while (list_size(*(env->a)) > 3)
	{
		pushed = 0;
		piv = env->sort[(stack_len + pushed_total) / 2];

		while (has_lower_piv(*(env->a), piv))
		{	
			while ((*(env->a))->val >= piv)
			{
				// Was only ra and it seems that it was better on 3-4 commands
				//if (path)
					command_dispatcher(env, "ra", 1);
				//else
				//	command_dispatcher(env, "rra", 1);
			}
			command_dispatcher(env, "pb", 1);
			pushed++;
		}
		plist_push(&push_list, plist_el_create(pushed, 'B'));
		pushed_total += pushed;
	}

	//ft_printf("Commands for stack-sort:\n");

	// Sort start
	numb = push_list->count > 3 ? 0 : push_list->count;
	//sort_three(a, b, NULL, numb, &cmd_full_str);
	sort_three(env, NULL, numb);
	if (numb != 0)
	{
		plist_pop_free(&push_list);			// should use free here probably
	}

	env->p_list = &push_list;

	stacks_sort(env);
}