/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:21:46 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/04 14:30:49 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

t_values	sa(long *a, long *b, t_values stack_values)
{
	int	number;

	if (stack_values.a_size == 0 || stack_values.a_size == 1)
	{
		ft_printf("\033[0;31ma stack is empty or there is a ");
		ft_printf("only a one nomber. Operation not work\n");
		ft_printf("\033[0;37m");
		return (stack_values);
	}
	number = 0;
	number = a[0];
	a[0] = a[1];
	a[1] = number;
	print_stack_struck(a, b, stack_values);
	return (stack_values);
}

t_values	sb(long *a, long *b, t_values stack_values)
{
	int	number;

	if (stack_values.b_size == 0 || stack_values.b_size == 1)
	{
		ft_printf("\033[0;31mb stack is empty or there is a ");
		ft_printf("only a one nomber. Operation not work\n");
		ft_printf("\033[0;37m");
		return (stack_values);
	}
	number = 0;
	number = b[0];
	b[0] = b[1];
	b[1] = number;
	print_stack_struck(a, b, stack_values);
	return (stack_values);
}

t_values	ra(long *a, long *b, t_values stack_values)
{
	int	number0;
	int	count;

	if (stack_values.a_size == 0 || stack_values.a_size == 1)
	{
		ft_printf("\033[0;31ma stack is empty or there is a ");
		ft_printf("only a one nomber. Operation not work\n");
		ft_printf("\033[0;37m");
		return (stack_values);
	}
	count = 0;
	number0 = a[count];
	count++;
	while (stack_values.a_size > count)
	{
		a[count - 1] = a[count];
		count++;
	}
	a[count - 1] = number0;
	print_stack_struck(a, b, stack_values);
	return (stack_values);
}

t_values	rb(long *a, long *b, t_values stack_values)
{
	int	number0;
	int	count;

	if (stack_values.b_size == 0 || stack_values.b_size == 1)
	{
		ft_printf("\033[0;31mb stack is empty or there is a ");
		ft_printf("only a one nomber. Operation not work\n");
		ft_printf("\033[0;37m");
		return (stack_values);
	}
	count = 0;
	number0 = b[count];
	count++;
	while (stack_values.b_size > count)
	{
		b[count - 1] = b[count];
		count++;
	}
	b[count - 1] = number0;
	print_stack_struck(a, b, stack_values);
	return (stack_values);
}

long	*new_pb_delete(long *array, long i)
{
	int	count;

	count = 0;
	count++;
	while (i > count)
	{
		array[count - 1] = array[count];
		count++;
	}
	return (array);
}
