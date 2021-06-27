/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:59:08 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/26 19:55:52 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_err(t_stack *a, t_stack *b)
{
	clear_stacks(a, b);
	raise_error(NULL, NULL);
}

void	swap(t_stack *stack)
{
	int	swap1;
	int	swap2;

	if (stack->size < 2)
		return ;
	swap1 = pop(stack);
	swap2 = pop(stack);
	push(stack, swap1);
	push(stack, swap2);
}
