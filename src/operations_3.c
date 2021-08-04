/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:29:38 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/03 19:49:29 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(int *a, int *b, int count, int i)
{
	a[i - 1] = b[count];
	rra_pa(a, i);
	if (count > 0)
		rrb(b, count);
	ft_printf("pa\n");
}

void	pb(int *a, int *b, int count, int i)
{
	b[count] = a[0];
	ra_pb(a, i);
	if (count > 0)
		rrb(b, count);
	ft_printf("pb\n");
}
