/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:30:16 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/04 13:45:48 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

t_values	rra(long *a, long *b, t_values stack_values)
{
	long	number0;
	int		i;

	if (stack_values.a_size == 0 || stack_values.a_size == 1)
	{
		ft_printf("\033[0;31ma stack is empty or there is a ");
		ft_printf("only a one nomber. Operation not work\n");
		ft_printf("\033[0;37m");
		return (stack_values);
	}
	i = stack_values.a_size;
	i--;
	number0 = a[i];
	while (i)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = number0;
	print_stack_struck(a, b, stack_values);
	return (stack_values);
}

t_values	rrb(long *a, long *b, t_values stack_values)
{
	long	number0;
	int		i;

	if (stack_values.b_size == 0 || stack_values.b_size == 1)
	{
		ft_printf("\033[0;31ma stack is empty or there is a ");
		ft_printf("only a one nomber. Operation not work\n");
		ft_printf("\033[0;37m");
		return (stack_values);
	}
	i = stack_values.b_size;
	i--;
	number0 = b[i];
	while (i)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[i] = number0;
	print_stack_struck(a, b, stack_values);
	return (stack_values);
}

t_values	pb(long **a, long **b, t_values stack_values)
{
	if (stack_values.a_size > 0)
	{
		stack_values.b_size++;
		stack_values.a_size--;
		*b = new_pb_add(*b, *a[0], stack_values.b_size);
		*a = new_pb_delete(*a, stack_values.a_size);
		print_stack_struck(*a, *b, stack_values);
	}
	else
		ft_printf("\033[0;31ma stack is empty. Operation not work\n");
	ft_printf("\033[0;37m");
	return (stack_values);
}

t_values	pa(long **a, long **b, t_values stack_values)
{
	if (stack_values.b_size > 0)
	{
		stack_values.b_size--;
		stack_values.a_size++;
		*a = new_pb_add(*a, *b[0], stack_values.a_size);
		*b = new_pb_delete(*b, stack_values.b_size);
		print_stack_struck(*a, *b, stack_values);
	}
	else
		ft_printf("\033[0;31mb stack is empty. Operation not work\n");
	ft_printf("\033[0;37m");
	return (stack_values);
}

long	*new_pb_add(long *array, long add, int i)
{
	long	number;
	long	number1;

	number = array[0];
	array[0] = add;
	i--;
	while (i > 1)
	{
		number1 = array[i - 1];
		array[i] = number1;
		i--;
	}
	if (i >= 1)
	{
		array[1] = number;
	}
	return (array);
}
