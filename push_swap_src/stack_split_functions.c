#include "../includes/push_swap.h"

void		reserve()
{

}

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

//void		sort_three(t_stack **a, t_stack **b, t_plist *pa, int numb)
void		sort_three(t_stack **a, t_stack **b, t_plist *pa, int numb)
{
	int		numa;

	numa = pa ? pa->count : list_size(*a);
	numa = (numa > 3) ? 3 : numa;

	// stupid sort
	if (numa == 2)
	{
		if ((*a)->val > (*a)->next->val)
			command_dispatcher(a, b, "sa", 1); //swap(a);
	}
	if (numa == 3)
	{
		if ((*a)->val > (*a)->next->val &&
			(*a)->next->val < (*a)->next->next->val &&
			(*a)->next->next->val > (*a)->val)
			command_dispatcher(a, b, "sa", 1); //swap(a);
		else if ((*a)->val < (*a)->next->val &&
			(*a)->next->val > (*a)->next->next->val &&
			(*a)->next->next->val < (*a)->val)
		{
			command_dispatcher(a, b, "ra", 1); //rotate(a);
			command_dispatcher(a, b, "sa", 1); //swap(a);
			command_dispatcher(a, b, "rra", 1); //rrotate(a);
			command_dispatcher(a, b, "sa", 1); //swap(a);
		}
		else if ((*a)->val > (*a)->next->val &&
			(*a)->next->val > (*a)->next->next->val &&
			(*a)->next->next->val < (*a)->val)	// try without the 3rd
		{
			command_dispatcher(a, b, "sa", 1); //swap(a);
			command_dispatcher(a, b, "ra", 1); //rotate(a);
			command_dispatcher(a, b, "sa", 1); //rotate(a);
			command_dispatcher(a, b, "rra", 1); //rrotate(a);
			command_dispatcher(a, b, "sa", 1); //swap(a);
		}
		else if ((*a)->val > (*a)->next->val &&
			(*a)->next->val < (*a)->next->next->val &&
			(*a)->next->next->val < (*a)->val)
		{
			command_dispatcher(a, b, "sa", 1); //swap(a);
			command_dispatcher(a, b, "ra", 1); //rotate(a);
			command_dispatcher(a, b, "sa", 1); //swap(a);
			command_dispatcher(a, b, "rra", 1); //rrotate(a);
		}
		else if ((*a)->val < (*a)->next->val &&
			(*a)->next->val > (*a)->next->next->val &&
			(*a)->next->next->val > (*a)->val)
		{
			command_dispatcher(a, b, "ra", 1); //rotate(a);
			command_dispatcher(a, b, "sa", 1); //swap(a);
			command_dispatcher(a, b, "rra", 1); //rrotate(a);
		}
	}

	if (numb == 2)
	{
		if ((*b)->val < (*b)->next->val)
			command_dispatcher(a, b, "sb", 1); //swap(a);
	}
	if (numb == 3)
	{
		if ((*b)->val < (*b)->next->val &&
			(*b)->next->val > (*b)->next->next->val &&
			(*b)->next->next->val < (*b)->val)
			command_dispatcher(a, b, "sb", 1); //swap(a);
		else if ((*b)->val > (*b)->next->val &&
			(*b)->next->val < (*b)->next->next->val &&
			(*b)->next->next->val > (*b)->val)
		{
			command_dispatcher(a, b, "rb", 1); //rotate(a);
			command_dispatcher(a, b, "sb", 1); //swap(a);
			command_dispatcher(a, b, "rrb", 1); //rrotate(a);
			command_dispatcher(a, b, "sb", 1); //swap(a);
		}
		else if ((*b)->val < (*b)->next->val &&
			(*b)->next->val < (*b)->next->next->val &&
			(*b)->next->next->val > (*b)->val)	// try without the 3rd
		{
			command_dispatcher(a, b, "sb", 1); //swap(a);
			command_dispatcher(a, b, "rb", 1); //rotate(a);
			command_dispatcher(a, b, "sb", 1); //rrotate(a);
			command_dispatcher(a, b, "rrb", 1); //swap(a);
			command_dispatcher(a, b, "sb", 1); //swap(a);
		}
		else if ((*b)->val < (*b)->next->val &&
			(*b)->next->val > (*b)->next->next->val &&
			(*b)->next->next->val > (*b)->val)
		{
			command_dispatcher(a, b, "sb", 1); //swap(a);
			command_dispatcher(a, b, "rb", 1); //rotate(a);
			command_dispatcher(a, b, "sb", 1); //swap(a);
			command_dispatcher(a, b, "rrb", 1); //rrotate(a);
		}
		else if ((*b)->val > (*b)->next->val &&
			(*b)->next->val < (*b)->next->next->val &&
			(*b)->next->next->val < (*b)->val)
		{
			command_dispatcher(a, b, "rb", 1); //rotate(a);
			command_dispatcher(a, b, "sb", 1); //swap(a);
			command_dispatcher(a, b, "rrb", 1); //rrotate(a);
		}
	}

	while (numb--)
	{
		//printf("Pushed to A: %i\n", (*b)->val);
		command_dispatcher(a, b, "pa", 1);
	}
}

t_plist		*backpush_a(t_stack **a, t_stack **b, t_plist **p_list)
{
	int		i;

	i = (*p_list)->count;
	(*p_list)->to = 'A';
	while (i--)
		command_dispatcher(a, b, "pa", 1);
	//printf("Pushed back to A: %i\n", (*p_list)->count);
	return (*p_list);
}

t_plist		*backpush_b(t_stack **a, t_stack **b, int piv, t_plist **a_push)
{
	int		rot_counter;
	int		pushed;

	pushed = 0;
	rot_counter = 0;
	while (has_lower_piv(*a, piv))
	{
		while ((*a)->val >= piv)
		{
			command_dispatcher(a, b, "ra", 1);
			rot_counter++;
		}
		command_dispatcher(a, b, "pb", 1);
		pushed++;
	}
	(*a_push)->count -= pushed;
	while (rot_counter--)
		command_dispatcher(a, b, "rra", 1);
	//printf("Pushed bakc to B: %i\n", pushed);
	return (plist_el_create(pushed, 'B'));
}

void		stacks_sort(t_stack **a, t_stack **b, t_plist **p_list, int *s_arr)
{
	t_plist	*a_push;	// for the nearest push to A
	int		piv;
	int		full_size;
	int		sort_size;
	int		numb;

	full_size = list_size(*a) + list_size(*b);
	while ((*p_list))
	{
		sort_size = list_size(*a);
		a_push = backpush_a(a, b, p_list);
		while (a_push->count > 3)
		{
			piv = s_arr[(2 * full_size - sort_size - list_size(*a)) / 2];
			//printf("The pivot is: %i\n", piv);
			plist_push(p_list, backpush_b(a, b, piv, &a_push));
		}

		numb = ((*p_list)->to == 'B') ? (*p_list)->count : 0;
		sort_three(a, b, a_push, numb);
		plist_removeifa(p_list);
		if (numb != 0)
			plist_pop(p_list);				// need to free it ?
		// if (*(p_list)->count <= 3 &&
		// 	(!(a_push = find_plist_a(*p_list)) || a_push->count <= 3))		// how to find out how many elements you need to sort
		// {
		// 	sort_three(a, b, a_push, p_list->count);
		// }

	}
}

void		stack_main_split(t_stack **a, t_stack **b)
{
	int		*s_arr;
	int		stack_len;
	t_plist *push_list;
	//int		i;
	int		piv;
	int		pushed_total;
	int		pushed;
	//t_stack	*iter;
	//t_plist	*tp_iter;
	int		numb;

	push_list = NULL;
	stack_len = list_size(*a);
	s_arr = list_to_arr_sort(*a);

	pushed_total = 0;

	printf("Commands for main split:\n");

	while (list_size(*a) > 3)
	{
		pushed = 0;
		piv = s_arr[(stack_len + pushed_total) / 2];
		// printf("Piv is: %i\n", piv);
		// sleep(1);
		while (has_lower_piv(*a, piv))
		{
			while ((*a)->val >= piv)
				command_dispatcher(a, b, "ra", 1); //rotate(a);
			command_dispatcher(a, b, "pb", 1); //push(b, pop(a));
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

	printf("Commands for stack-sort:\n");

	// Sort start
	numb = push_list->count > 3 ? 0 : push_list->count;
	sort_three(a, b, NULL, numb);
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

	stacks_sort(a, b, &push_list, s_arr);
	// sort_three(a, b, NULL, push_list->count);		// should be called from stacks_sort()
	// plist_pop(&push_list);							// need to free and use only with IF
	// sort_three(a, b, NULL, push_list->count);
	// plist_pop(&push_list);							// need to free and use only with IF

	// After sort or something that looks like sort :)
	printf("Stacks after sort operations\n");
	debug_info(*a, *b, NULL);

	// // Test last pivot
	// piv = s_arr[(2 * stack_len - 2 * list_size(*a) - push_list->count) / 2];
	// //piv = (2 * stack_len - 2 * list_size(*a) - push_list->count) / 2;
	// printf("\n\nThe last pivot is: %i.\n", piv);

	printf("Push list:\n");
	while (push_list)
	{
		printf("Pushed: %i, to %c.\n", push_list->count, push_list->to);
		push_list = push_list->next;
	}	
}