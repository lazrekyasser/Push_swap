/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:58:16 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/26 18:53:31 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *stack)
{
	t_stack	tmp;
	int		first;

	if (stack->size <= 1)
		return ;
	first = pop(stack);
	tmp.size = 0;
	while (stack->size)
		push(&tmp, pop(stack));
	push(stack, first);
	while (tmp.size)
		push(stack, pop(&tmp));
}

void	r_rotate(t_stack *stack)
{
	t_stack	tmp;
	int		first;

	if (stack->size <= 1)
		return ;
	tmp.size = 0;
	while (stack->size > 1)
		push(&tmp, pop(stack));
	first = pop(stack);
	while (tmp.size)
		push(stack, pop(&tmp));
	push(stack, first);
}

void	print_error(char *er, t_stack *a, t_stack *b)
{
	ft_putstr_fd(er, 1);
	if (a != NULL && b != NULL)
		clear_stacks(a, b);
	exit(EXIT_FAILURE);
}

void	init_stackb(t_stack *b)
{
	b->node = NULL;
	b->chunk_size = NULL;
	b->chunk = NULL;
	b->size = 0;
}

void	clear_stacks(t_stack *a, t_stack *b)
{
	ft_lstclear(&a->node, free);
	ft_lstclear(&b->node, free);
}
