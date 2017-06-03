/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_to_arr_sort.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:26:01 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/06/03 14:26:03 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			*list_to_arr(t_stack *s_top, size_t num_el)
{
	size_t	i;
	int		*res;

	res = (int *)malloc(sizeof(int) * num_el);
	if (!res || !s_top)
		return (NULL);
	i = 0;
	while (++i <= num_el && s_top)
	{
		res[i - 1] = s_top->val;
		s_top = s_top->next;
	}
	return (res);
}

int			asc(int a, int b)
{
	return (a <= b);
}

int			is_sorted_tab(int *tab, int s, int e, int (*f)(int, int))
{
	while (s < e)
	{
		if (!(*f)(tab[s], tab[s + 1]))
		{
			ft_printf("tab[s]: %i   tab[s+1]: %i\n", tab[s], tab[s + 1]);
			return (0);
		}
		s++;
	}
	return (1);
}

void		arr_qsort_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		arr_qsort(int s, int e, int *arr, int *swaps)
{
	int		l;
	int		r;
	int		piv;

	l = s;
	r = e;
	piv = arr[(l + r) / 2];
	while (l <= r)
	{
		while (arr[l] < piv)
			l++;
		while (arr[r] > piv)
			r--;
		if (l <= r)
		{
			arr_qsort_swap(&arr[l++], &arr[r--]);
			(*swaps)++;
		}
	}
	if (r > s)
		arr_qsort(s, r, arr, swaps);
	if (l < e)
		arr_qsort(l, e, arr, swaps);
}

int			list_size(t_stack *list)
{
	int		count;

	count = 0;
	while (list && (++count))
		list = list->next;
	return (count);
}

int			*list_to_arr_sort(t_stack *list)
{
	int		*int_tab;
	int		tab_size;
	int		swaps;

	tab_size = list_size(list);
	int_tab = list_to_arr(list, tab_size);
	swaps = 0;
	arr_qsort(0, tab_size - 1, int_tab, &swaps);
	return (int_tab);
}
