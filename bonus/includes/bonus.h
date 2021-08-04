/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:28:49 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/04 14:19:25 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdio.h>
# include <unistd.h>
# include "stdlib.h"
# include "../../ft_printf/includes/ft_printf.h"

char			*get_next_line(int fd);

typedef struct s_values
{
	int		a_size;
	int		b_size;
}	t_values;

long			operations_exist(char *operations);
t_values		do_operations_2(char *operations, long **a, long **b,
					t_values stack_values);
t_values		do_operations(char *operations, long **a, long **b,
					t_values stack_values);
void			print_stack_struck(long *a, long *b, t_values stack_values);
long			*get_int_array(char **argv);
void			checker(long *a, long *b, t_values stack_values);
void			write_welcome(long *a, long size, int i);
long			*new_pb_delete(long *array, long i);
long			*new_pb_add(long *array, long add, int i);
t_values		sa(long *a, long *b, t_values stack_values);
t_values		sb(long *a, long *b, t_values stack_values);
t_values		ra(long *a, long *b, t_values stack_values);
t_values		rb(long *a, long *b, t_values stack_values);
t_values		rra(long *a, long *b, t_values stack_values);
t_values		rrb(long *a, long *b, t_values stack_values);
t_values		pb(long **a, long **b, t_values stack_values);
t_values		pa(long **a, long **b, t_values stack_values);


#endif
