/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:30:20 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/03 19:49:35 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(int *a, int i)
{
	if (a[0] > a[1] && a[0] < a[2] && a[1] < a[2])
		sa(a);
	if (a[0] > a[1] && a[0] > a[2] && a[1] > a[2])
	{
		sa(a);
		rra(a, i);
	}
	if (a[0] > a[1] && a[0] > a[2] && a[1] < a[2])
		ra(a, i);
	if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
	{
		sa(a);
		ra(a, i);
	}
	if (a[0] < a[1] && a[0] > a[2] && a[1] > a[2])
		rra(a, i);
}

void	sort_2(int *a)
{
	if (a[0] > a[1])
		sa(a);
}

void	sort(int *a, int *b, int i)
{
	int	j;
	int	count;
	int	k;

	k = i;
	count = 0;
	while (k > count && k - count != 3)
	{
		j = get_lower(a, i);
		to_the_top(a, j, i);
		pb(a, b, count, i);
		count++;
		i--;
	}
	sort_3(a, 3);
	rrb(b, count);
	i = k;
	count = 0;
	while (k > count && k - count != 3)
	{
		pa(a, b, count, i);
		count++;
	}
}

int	is_sorted(int *a)
{
	int	i;

	i = 1;
	while (a[i])
	{
		if (a[i - 1] > a[i])
			return (0);
		i++;
	}
	return (1);
}
