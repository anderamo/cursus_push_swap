/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:51:25 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/04 14:32:43 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

void	print_stack_a(long *a, int i)
{
	if (a[i] == 2148473648)
		ft_printf("				2148473648				-		\n");
	else if (a[i] == -2148473648)
		ft_printf("				-2148473648				-		\n");
	else
		ft_printf("				%d					-		\n", a[i]);
}

void	print_stack_b(long *b, int i)
{
	if (b[i] == 2148473648)
		ft_printf("				-				2148473648		\n");
	else if (b[i] == -2148473648)
		ft_printf("				-				-2148473648		\n");
	else
		ft_printf("				-					%d		\n", b[i]);
}

void	print_stack_a_b(long *a, long *b, int i)
{
	if (a[i] == 2148473648)
		ft_printf("				2148473648				-		\n");
	else if (a[i] == -2148473648)
		ft_printf("				-2148473648				-		\n");
	else
		ft_printf("				%d					-		\n", a[i]);
	if (b[i] == 2148473648)
		ft_printf("				-				2148473648		\n");
	else if (b[i] == -2148473648)
		ft_printf("				-				-2148473648		\n");
	else
		ft_printf("				-					%d		\n", b[i]);
}

void	print_stack_struck(long *a, long *b, t_values stack_values)
{
	int	i;

	i = 0;
	ft_printf("--------------------------------------------------------------");
	ft_printf("----------------------------------------------------------\n");
	ft_printf("				a stack					b stack				\n");
	ft_printf("				-------					-------			\n");
	while (stack_values.a_size > i || stack_values.a_size > i)
	{
		if (stack_values.a_size > i && stack_values.b_size > i)
			print_stack_a_b(a, b, i);
		else if (stack_values.a_size > i)
			print_stack_a(a, i);
		else
			print_stack_b(b, i);
		i++;
	}
	ft_printf("--------------------------------------------------------------");
	ft_printf("----------------------------------------------------------\n");
}
