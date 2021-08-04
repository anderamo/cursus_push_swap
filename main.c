/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:13:22 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/04 13:15:41 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	get_lower(int *a, int i)
{
	int	j;
	int	lower;

	j = 1;
	lower = 0;
	while (i > j)
	{
		if (a[lower] > a[j])
			lower = j;
		j++;
	}
	return (lower);
}

void	to_the_top(int *a, int j, int i)
{
	int	count;

	count = 0;
	if (j == 0)
	{
		return ;
	}
	if (i - j < j)
	{
		while (count++ < i - j)
			rra(a, i);
	}
	else
	{
		while (count++ < j)
			ra(a, i);
	}
}

int	get_biarray_len(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		i++;
		argv++;
	}
	return (i);
}

void	push_swap(char **argv)
{
	int	i;
	int	*a;
	int	*b;
	int	items;

	i = 0;
	items = get_biarray_len(argv);
	a = malloc(items * sizeof(int));
	b = malloc((items - 3) * sizeof(int));
	while (items > i)
	{
		a[i] = ft_atoi_perf(argv[i]);
		i++;
	}
	if (is_sorted(a))
		return ;
	if (i == 2)
		sort_2(a);
	else if (i == 3)
		sort_3(a, i);
	else if (i != 1)
		sort(a, b, i);
	free(b);
	free(a);
}

int	main(int items, char *argv[])
{
	if (items > 1)
	{
		argv++;
		if (items == 2)
			argv = ft_split(*argv, ' ');
		push_swap(argv);
		return (0);
	}
	ft_printf("Error\n");
	return (0);
}
