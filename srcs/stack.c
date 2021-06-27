/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:47:07 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/22 18:35:45 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_new(t_stack *stack)
{
	stack->node = NULL;
	stack->size = 0;
	stack->chunk = NULL;
	stack->chunk_size = NULL;
	stack->pivot = NULL;
	stack->type_swap = NONE;
}

void	stack_clear(t_stack *a)
{
	t_list	*prev;
	t_list	*curr;

	curr = a->node;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(a);
}

void	stack_addback(t_stack *a, int val)
{
	t_list	*new;
	t_list	*tmp;
	int		*nval;

	nval = (int *)malloc(sizeof(int));
	*nval = val;
	new = ft_lstnew(nval);
	a->size += 1;
	tmp = a->node;
	if (!a->node)
		a->node = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	free(nval);
}

void	stack_show(t_stack *a)
{
	t_list	*p;

	if (!a->node)
	{
		ft_putstr_fd("stack emty\n", 1);
		return ;
	}
	p = a->node;
	ft_putstr_fd("__\n", 1);
	while (p)
	{
		ft_putnbr_fd(*(int *)p->content, 1);
		ft_putendl_fd("\n", 1);
		p = p->next;
	}
	ft_putstr_fd("__\n", 1);
	ft_putstr_fd("a\n", 1);
}
