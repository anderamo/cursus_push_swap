/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:27:00 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/03 19:50:16 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(int *num)
{
	int	number;

	number = 0;
	number = num[0];
	num[0] = num[1];
	num[1] = number;
	ft_printf("sa\n");
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
	while (i)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = number0;
	ft_printf("rra\n");
}

void	rrb(int *b, int i)
{
	int	number0;

	i--;
	number0 = b[i];
	while (i)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[i] = number0;
}

void	ra(int *num, int i)
{
	int	number0;
	int	count;

	count = 0;
	number0 = num[count];
	count++;
	while (i > count)
	{
		num[count - 1] = num[count];
		count++;
	}
	num[count - 1] = number0;
	ft_printf("ra\n");
}
