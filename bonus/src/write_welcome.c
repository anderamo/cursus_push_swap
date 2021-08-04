/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_welcome.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:38:17 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/04 16:34:14 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

void	write_welcome2(void)
{
	ft_printf("--------------------------------------------------------------");
	ft_printf("----------------------------------------------------------\n");
	ft_printf("If you write a wrong operation the program return Error.\n");
	ft_printf("To check that the a stack is sort press enter(without anything");
	ft_printf(" more).If the numbers are already sorted or you sort with");
	ft_printf(" operations the program return\033[0;32m OK\033[0;37m, else\n");
	ft_printf("\033[0;31mKO\033[0;37m. Write the operation and press enter.\n");
	ft_printf("GL!!!!(Good Luck:)!!!!!)\nStart writing operations\n");
	ft_printf("--------------------------------\n");
}

void	write_welcome(long *a, long size, int i)
{
	ft_printf("Hello welcome!! Write operations to get the numberssorted.");
	ft_printf(" For that we have 2 stacks and you can use them as you want.\n");
	ft_printf("The a stack will start with the numbers that you write from");
	ft_printf("parameters and b stack use as you want at the moment");
	ft_printf("it will be empty.\nLike that!.\n");
	ft_printf("--------------------------------------------------------------");
	ft_printf("----------------------------------------------------------\n");
	ft_printf("				a stack					b stack				\n");
	ft_printf("				-------					-------			\n");
	while (size > i)
	{
		if (a[i] == 2148473648)
			ft_printf("				2148473648				-		\n", a[i]);
		else if (a[i] == -2148473648)
			ft_printf("				-2148473648				-		\n", a[i]);
		else
			ft_printf("				%d					-		\n", a[i]);
		i++;
	}
	write_welcome2();
}
