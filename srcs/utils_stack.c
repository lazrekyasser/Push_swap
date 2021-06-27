/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:55:42 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/11 10:53:29 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	deletefirstnode(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstdelone(tmp, free);
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_list	*tmp_l;

	tmp = ft_calloc(1, sizeof(t_stack));
	tmp->node = NULL;
	tmp->size = 0;
	tmp_l = stack->node;
	while (stack->size != tmp->size)
	{
		push(tmp, *(int *)tmp_l->content);
		tmp_l = tmp_l->next;
	}
	return (tmp);
}

int	check_sorted(t_stack *stack_a)
{
	t_list	*tmp;

	if (!stack_a->size)
		return (0);
	tmp = stack_a->node;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
