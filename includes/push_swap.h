/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:38:38 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/03 20:05:14 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "stdlib.h"
# include "../ft_printf/includes/ft_printf.h"

void	sort_2(int *a);
void	sort(int *a, int *b, int i);
void	sort_3(int *a, int i);
int		is_sorted(int *a);
void	sa(int *num);
void	sb(int *num);
void	rra(int *a, int i);
void	rrb(int *b, int i);
void	ra(int *num, int i);
void	rra_pa(int *a, int i);
void	ra_pb(int *num, int i);
void	rb(int *num, int i);
void	rb_pa(int *num, int i);
void	rb_pa(int *num, int i);
void	pb(int *a, int *b, int count, int i);
void	pa(int *a, int *b, int count, int i);
int		get_lower(int *a, int i);
void	to_the_top(int *a, int j, int i);

#endif
