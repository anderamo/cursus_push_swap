/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:07:03 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/04 16:27:10 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

long	operations_exist(char *operations)
{
	if (ft_strcmp(operations, "sa\n") || ft_strcmp(operations, "sb\n")
		|| ft_strcmp(operations, "ss\n") || ft_strcmp(operations, "ra\n")
		|| ft_strcmp(operations, "rb\n") || ft_strcmp(operations, "rra\n")
		|| ft_strcmp(operations, "rrb\n") || ft_strcmp(operations, "rrr\n")
		|| ft_strcmp(operations, "pa\n") || ft_strcmp(operations, "pb\n")
		|| ft_strcmp(operations, "rr\n"))
		return (1);
	else
		return (0);
}

t_values	do_operations_2(char *operations, long **a, long **b,
					t_values stack_values)
{
	if (ft_strcmp(operations, "rra\n"))
		stack_values = rra(*a, *b, stack_values);
	else if (ft_strcmp(operations, "rrb\n"))
		stack_values = rrb(*a, *b, stack_values);
	else if (ft_strcmp(operations, "rrr\n"))
	{
		stack_values = rra(*a, *b, stack_values);
		stack_values = rrb(*a, *b, stack_values);
	}
	else if (ft_strcmp(operations, "pa\n"))
		stack_values = pa(a, b, stack_values);
	else if (ft_strcmp(operations, "pb\n"))
		stack_values = pb(a, b, stack_values);
	return (stack_values);
}

t_values	do_operations(char *operations, long **a, long **b,
					t_values stack_values)
{
	if (ft_strcmp(operations, "sa\n"))
		stack_values = sa(*a, *b, stack_values);
	else if (ft_strcmp(operations, "sb\n"))
		stack_values = sb(*a, *b, stack_values);
	else if (ft_strcmp(operations, "ss\n"))
	{
		stack_values = sa(*a, *b, stack_values);
		stack_values = sb(*a, *b, stack_values);
	}
	else if (ft_strcmp(operations, "ra\n"))
		stack_values = ra(*a, *b, stack_values);
	else if (ft_strcmp(operations, "rb\n"))
		stack_values = rb(*a, *b, stack_values);
	else if (ft_strcmp(operations, "rr\n"))
	{
		stack_values = ra(*a, *b, stack_values);
		stack_values = rb(*a, *b, stack_values);
	}
	stack_values = do_operations_2(operations, a, b, stack_values);
	return (stack_values);
}
