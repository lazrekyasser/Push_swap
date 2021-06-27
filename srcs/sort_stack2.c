/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:27:52 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/22 17:28:07 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_chunk_a(t_stack *stack, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (stack->chunk)
		ft_lstclear(&stack->chunk, free);
	stack->chunk = NULL;
	if (!size || !stack->node)
		return ;
	tmp = stack->node;
	while (i < size)
	{
		ft_lstadd_back(&stack->chunk,
			ft_lstnew(alloc_size(*(int *)tmp->content)));
		tmp = tmp->next;
		i++;
	}
}

void	get_chunk(t_stack *stack, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (stack->chunk)
		ft_lstclear(&stack->chunk, free);
	stack->chunk = NULL;
	if (!stack->chunk_size || !stack->node)
		return ;
	tmp = stack->node;
	while (i < size)
	{
		ft_lstadd_back(&stack->chunk,
			ft_lstnew(alloc_size(*(int *)tmp->content)));
		tmp = tmp->next;
		i++;
	}
}

int	is_desc(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	*get_pivot(t_list *lst)
{
	int	*ret;
	int	*tab;

	ret = NULL;
	ret = (int *)malloc(sizeof(int));
	tab = list_to_tab(lst);
	quicksort(tab, 0, ft_lstsize(lst) - 1);
	*ret = tab[ft_lstsize(lst) / 2];
	free(tab);
	return (ret);
}

int	check_less_pivot(t_list *lst, int pivot)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (*(int *)tmp->content < pivot)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
