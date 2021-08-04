/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:26:54 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/04 16:22:35 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bonus.h"

t_values	init_values(void)
{
	t_values	values;

	values.a_size = 0;
	values.b_size = 0;
	return (values);
}

int	main(int items, char *argv[])
{
	long			*a;
	long			*b;
	int				i;
	t_values		stack_values;

	i = 1;
	if (items > 1)
	{
		argv++;
		if (items == 2)
			argv = ft_split(*argv, ' ');
		a = get_int_array(argv);
		stack_values = init_values();
		stack_values.a_size = items - 1;
		write_welcome(a, stack_values.a_size, 0);
		b = malloc(stack_values.a_size * sizeof(long));
		checker(a, b, stack_values);
	}
	ft_printf("\033[0;31mError\n");
	return (0);
}
