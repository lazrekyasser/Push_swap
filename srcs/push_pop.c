/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:59:47 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/15 17:43:27 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *stack, int item)
{
	int	*data;

	data = ft_calloc(1, sizeof(int));
	*data = item;
	ft_lstadd_front(&stack->node, ft_lstnew(data));
	stack->size++;
}

int	pop(t_stack *stack)
{
	int		val;
	t_list	*tmp;

	val = *(int *)stack->node->content;
	tmp = stack->node;
	stack->node = stack->node->next;
	stack->size--;
	free(tmp->content);
	free(tmp);
	return (val);
}
