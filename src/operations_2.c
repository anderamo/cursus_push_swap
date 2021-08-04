/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:28:15 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/03 19:49:53 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_pa(int *a, int i)
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
}

void	ra_pb(int *num, int i)
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
}

void	rb(int *num, int i)
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
}

void	rb_pa(int *num, int i)
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
}
