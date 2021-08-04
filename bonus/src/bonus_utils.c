/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:31:31 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/04 17:17:42 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

long	get_biarray_len(char **argv)
{
	long	i;

	i = 0;
	while (*argv)
	{
		i++;
		argv++;
	}
	return (i);
}

int	repet_it(long *a, int items)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (items > i)
	{
		while (items > k)
		{
			if (a[i] == a[k])
				return (0);
			k++;
		}
		i++;
		k = i + 1;
	}
	return (1);
}

long	*get_int_array(char **argv)
{
	int		i;
	long	*a;
	int		items;

	i = 0;
	items = get_biarray_len(argv);
	a = malloc(items * sizeof(long));
	while (items > i)
	{
		a[i] = ft_atoi_perf(argv[i]);
		if (a[i] < -2148473648 || a[i] > 2148473648)
		{
			ft_printf("\033[0;31mError\n");
			exit(1);
		}
		i++;
	}
	if (!repet_it(a, items))
	{
		ft_printf("\033[0;31mError\n");
		exit (1);
	}
	return (a);
}

long	is_sorted(long *a, t_values stack_values)
{
	int	i;

	i = 1;
	if (stack_values.b_size != 0)
		return (0);
	while (stack_values.a_size > i)
	{
		if (a[i - 1] > a[i])
			return (0);
		i++;
	}
	ft_printf("\033[0;32mOK\n");
	return (1);
}

void	checker(long *a, long *b, t_values stack_values)
{
	char		*operations;

	while (1)
	{
		operations = get_next_line(0);
		if (ft_strcmp(operations, "\n"))
		{
			if (is_sorted(a, stack_values))
				exit (1);
			else
			{
				ft_printf("\033[0;31mK0\n");
				exit (1);
			}
		}
		if (!operations_exist(operations))
		{
			return ;
		}
		stack_values = do_operations(operations, &a, &b, stack_values);
	}
}
