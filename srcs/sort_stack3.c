/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:24:56 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/26 20:49:07 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_greater_pivot(t_list *lst, int pivot)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (*(int *)tmp->content > pivot)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_closestless2(int *tab, int size, int pivot, int type)
{
	int	i;

	if (type == 1)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] < pivot)
				return (i);
			i++;
		}
		return (0);
	}
	else if (type == 2)
	{
		i = size - 1;
		while (i > size / 2)
		{
			if (tab[i] < pivot)
				return (i);
			i--;
		}
		return (i);
	}
	return (0);
}

int	*get_closestless(t_stack *stack, int pivot)
{
	int				*ret;
	int				*tab;
	int				i;
	unsigned int	count;

	i = 0;
	count = 0;
	ret = (int *)malloc(sizeof(int) * 2);
	tab = list_to_tab(stack->node);
	count = get_closestless2(tab, stack->size, pivot, 1);
	i = get_closestless2(tab, stack->size, pivot, 1);
	if (count < stack->size - i)
	{
		ret[0] = count;
		ret[1] = 0;
	}
	else
	{
		ret[0] = stack->size - i;
		ret[1] = 1;
	}
	free(tab);
	return (ret);
}

int	total_chunks(t_stack *stack)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = stack->chunk_size;
	while (tmp)
	{
		count += *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (count);
}

void	check_rot(t_stack *stack_a, t_stack *stack_b)
{
	int	*check_rot;

	check_rot = get_closestless(stack_a, *stack_a->pivot);
	while (check_rot[0])
	{
		if (check_rot[1] == 0)
			exec_ins("ra", stack_a, stack_b);
		else
			exec_ins("rra", stack_a, stack_b);
		check_rot[0]--;
	}
	free(check_rot);
}
