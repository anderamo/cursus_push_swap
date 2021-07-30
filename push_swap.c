/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:13:22 by aamorin-          #+#    #+#             */
/*   Updated: 2021/07/30 18:08:01 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf/includes/ft_printf.h"

int	a_items(int *a)
{
	int i;

	i = 0;
	while (*a++)
	{
		i++;
	}
	return (i);

}

void	sa(int *num)
{
	int	number;

	number = 0;
	number = num[0];
	num[0] = num[1];
	num[1] = number;
	write(1, "sa\n" , 3);
	//ft_printf("sa\n");
}

void	sb(int *num)
{
	int	number;

	number = 0;
	number = num[0];
	num[0] = num[1];
	num[1] = number;
}

void	rra(int *a, int i)
{
	int	number0;

	i--;
	number0 = a[i];
	while(i)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = number0;
	write(1, "rra\n" , 4);
	//ft_printf("rra\n");
}

void	rrb(int *b, int i)
{
	int	number0;

	i--;
	number0 = b[i];
	while(i)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[i] = number0;
}

void	ra(int *num, int i)
{
	int	number0;
	int count;

	count = 0;
	number0 = num[count];
	count++;
	while(i > count)
	{
		num[count - 1] = num[count];
		count++;
	}
	num[count - 1] = number0;
	write(1, "ra\n" , 3);
	//ft_printf("ra\n");
}

void	rb(int *num, int i)
{
	int	number0;
	int count;

	count = 0;
	number0 = num[count];
	count++;
	while(i > count)
	{
		num[count - 1] = num[count];
		count++;
	}
	num[count - 1] = number0;
	write(1, "rb\n" , 3);
	//ft_printf("rb\n");
}

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

int	get_lower(int *a, int i)
{
	int	j;
	int lower;

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
	int count;

	count = 0;
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

void	pa(int *a, int *b, int count, int i)
{
	b[count] = a[0];
	rb(a, i);
	if (count > 0)
		rrb(b, count);
}

void	pb(int *a, int *b, int count, int i)
{
	b[count] = a[0];
	ra(a, i);
	if (count > 0)
		rrb(b, count);
}

void	sort(int *a, int *b, int i)
{
	int	j;
	int count;
	int	k;

	k = i;
	count = 0;
	while (k > count)
	{
		j = get_lower(a, i);
		to_the_top(a, j, i);
		pb(a, b, count, i);
		count++;
		i--;
	}
	rrb(b, count);
	i = k;
	count = 0;
	while (k > count)
	{
		pa(a, b, count, i);
		count++;
		i--;
	}

}

void	push_swap(int items, char **argv)
{
	int	i;
	int	*a;
	int	*b;

	i = 0;
	a = malloc(items * sizeof(int));
	b = malloc(items * sizeof(int));
	while (items > i)
	{
		a[i] = ft_atoi_perf(argv[i]);
		i++;
	}
	if (i == 2)
		sort_2(a);
	else if (i == 3)
		sort_3(a, i);
	else if (i != 1)
		sort(a, b, i);
	free(b);
}

int	main(int items, char *argv[])
{
	if (items > 1)
	{
		if (items == 2)
			return (0);
		argv++;
		push_swap(items - 1, argv);
		return (0);
	}
	ft_printf("Error\n");
	return (0);
}
