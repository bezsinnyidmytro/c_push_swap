#include <stdlib.h>
#include <stdio.h>
#include "../includes/push_swap.h"

#define S 1;
#define E 2;
#define L 3;
#define R 4;

int		*list_to_arr(t_stack *s_top, size_t num_el)
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
	// if there is not enough elements in stack you need to free array and return NULL
	return (res);
}

int		asc(int a, int b)
{
	return (a <= b);
}

int		is_sorted_tab(int *tab, int s, int e, int (*f)(int, int))
{
	while (s < e)
	{
		if (!(*f)(tab[s], tab[s + 1]))
		{
			printf("tab[s]: %i   tab[s+1]: %i\n", tab[s], tab[s + 1]);
			return (0);
		}
		s++;
	}
	return (1);
}

void	arr_qsort_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	arr_qsort(int s, int e, int *arr, int *swaps)
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

int		list_size(t_stack *list)
{
	int		count;

	count = 0;
	while (list && (++count))
		list = list->next;
	return (count);
}

int		*list_to_arr_sort(t_stack *list)
{
	int		*int_tab;
	int		tab_size;
	//int		i;
	int		swaps;
	//double	piv;
	//int		less_than_piv;

	tab_size = list_size(list);
	
	//printf("The size of stack is: %i\n", tab_size);
	
	int_tab = list_to_arr(list, tab_size);
	// int_tab = (int *)malloc(sizeof(int) * tab_size);
	// i = -1;
	// while (++i < tab_size)
	// 	int_tab[i] = atoi(av[i + 1]);

	// print tab
	// i = -1;
	// printf("Not sorted int_tab:\n");
	// while (++i < tab_size)
	// 	printf("%d ", int_tab[i]);
	//arr_qsort(0, tab_size - 1, int_tab);


	swaps = 0;
	arr_qsort(0, tab_size - 1, int_tab, &swaps);
	

	//printf("\n");
	// print tab after sort

	// i = -1;
	// printf("Sorted int_tab:\n");
	// while (++i < tab_size)
	// 	printf("%d ", int_tab[i]);
	// printf("\n\n");
	// //piv = (tab_size % 2) ? int_tab[tab_size / 2] : (int_tab[tab_size / 2 + 1] + int_tab[tab_size / 2 -1]) / 2.0;
	// piv = int_tab[tab_size / 2];
	is_sorted_tab(int_tab, 0, tab_size - 1, &asc) ? printf("Is sorted: OK\n") : printf("Is sorted: KO\n");
	// printf("\nNumber of element swaps: %i\n", swaps);
	// printf("\nPivot is: %f\n", piv);
	// i = -1;
	// less_than_piv = 0;
	// while (++i < tab_size && int_tab[i] < piv)
	// 	less_than_piv++;
	// printf("\nNum elements less than Pivot: %i\n", less_than_piv);
	// printf("\nNum elements more than or equal to Pivot: %i\n\n", tab_size - less_than_piv);
	
	return (int_tab);
	// return (0);
}

// int		main(int ac, char **av)
// {
// 	int		*int_tab;
// 	int		tab_size;
// 	int		i;
// 	int		swaps;
// 	double	piv;
// 	int		less_than_piv;

// 	if (ac > 1)
// 	{
// 		tab_size = ac - 1;
// 		int_tab = (int *)malloc(sizeof(int) * tab_size);
// 		i = -1;
// 		while (++i < tab_size)
// 			int_tab[i] = atoi(av[i + 1]);

// 		// print tab
// 		// i = -1;
// 		// printf("Not sorted int_tab:\n");
// 		// while (++i < tab_size)
// 		// 	printf("%d ", int_tab[i]);
// 		//arr_qsort(0, tab_size - 1, int_tab);
// 		swaps = 0;
// 		arr_qsort(0, tab_size - 1, int_tab, &swaps);
// 		//printf("\n");
// 		// print tab after sort
// 		i = -1;
// 		printf("Sorted int_tab:\n");
// 		while (++i < tab_size)
// 			printf("%d ", int_tab[i]);
// 		printf("\n\n");
// 		//piv = (tab_size % 2) ? int_tab[tab_size / 2] : (int_tab[tab_size / 2 + 1] + int_tab[tab_size / 2 -1]) / 2.0;
// 		piv = int_tab[tab_size / 2];
// 		is_sorted_tab(int_tab, 0, tab_size - 1, &asc) ? printf("Is sorted: OK\n") : printf("Is sorted: KO\n");
// 		printf("\nNumber of element swaps: %i\n", swaps);
// 		printf("\nPivot is: %f\n", piv);
// 		i = -1;
// 		less_than_piv = 0;
// 		while (++i < tab_size && int_tab[i] < piv)
// 			less_than_piv++;
// 		printf("\nNum elements less than Pivot: %i\n", less_than_piv);
// 		printf("\nNum elements more than or equal to Pivot: %i\n\n", tab_size - less_than_piv);
// 		return (1);
// 	}
// 	return (0);
// }