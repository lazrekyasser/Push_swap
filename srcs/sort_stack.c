/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:22:37 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/22 17:29:40 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	greater_to_a(t_stack *stack_a, t_stack *stack_b, int *push_count,
		int *s_chunk_a)
{
	int	times_rot;

	times_rot = 0;
	push_greater_pivot_to_a(stack_a, stack_b, times_rot, s_chunk_a);
	if (*(int *)stack_b->chunk_size->content == 0)
		deletefirstnode(&stack_b->chunk_size);
	ft_lstclear(&stack_b->chunk, free);
	get_chunk_a(stack_a, *s_chunk_a);
	*push_count = 0;
	if (stack_a->pivot)
		free(stack_a->pivot);
	stack_a->pivot = get_pivot(stack_a->chunk);
}

void	add_push_to_b(t_stack *stack_a, t_stack *stack_b, int *push_count,
		int *push_c)
{
	if (*push_count != 0)
	{
		push_c = malloc(sizeof(int));
		*push_c = *push_count;
		ft_lstadd_front(&stack_b->chunk_size, ft_lstnew(push_c));
	}
	*push_count = 0;
	free(stack_a->pivot);
	stack_a->pivot = get_pivot(stack_a->chunk);
}

int	work_a(t_stack *stack_a, t_stack *stack_b, int *push_count, int *s_chunk_a)
{
	int	*push_c;

	push_c = NULL;
	get_chunk_a(stack_a, *s_chunk_a);
	if (stack_a->chunk && *s_chunk_a <= 2)
	{
		if (check_sorted(stack_a))
			exec_ins("sa", stack_a, stack_b);
		if (*push_count != 0)
		{
			push_c = malloc(sizeof(int));
			*push_c = *push_count;
			ft_lstadd_front(&stack_b->chunk_size, ft_lstnew(push_c));
		}
		*s_chunk_a = 0;
		*push_count = 0;
		return (1);
	}
	else if (check_less_pivot(stack_a->chunk, *stack_a->pivot))
		add_push_to_b(stack_a, stack_b, push_count, push_c);
	else
		push_less_pivot_to_b(stack_a, stack_b, push_count, s_chunk_a);
	return (0);
}

int	sort_stack2(t_stack *stack_a, t_stack *stack_b, int size_b, int s_chunk_a)
{
	int	push_count;

	get_chunk(stack_b, *(int *)stack_b->chunk_size->content);
	if (nor_handle_up(stack_a, stack_b, size_b) == 1)
		return (1);
	else if (handle_upper_chunk_b(stack_a, stack_b))
		;
	else if (!check_greater_pivot(stack_b->chunk, *stack_b->pivot)
		&& !check_sorted(stack_a))
	{
		greater_to_a(stack_a, stack_b, &push_count, &s_chunk_a);
		while (1)
		{
			if (work_a(stack_a, stack_b, &push_count, &s_chunk_a) == 1)
				break ;
		}
	}
	return (0);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_a_size;
	int	size_b;

	stack_a->pivot = get_pivot(stack_a->node);
	while (1)
		if (push_a_to_b(stack_a, stack_b) == 1)
			break ;
	ft_lstadd_front(&stack_b->chunk_size,
		ft_lstnew(alloc_size(stack_b->size - total_chunks(stack_b))));
	chunk_a_size = 0;
	size_b = 0;
	get_chunk(stack_b, *(int *)stack_b->chunk_size->content);
	stack_b->pivot = get_pivot(stack_b->chunk);
	while (stack_b->size)
	{
		if (sort_stack2(stack_a, stack_b, size_b, chunk_a_size))
			break ;
	}
	free(stack_a->pivot);
	free(stack_b->pivot);
	exec_ins("end", stack_a, stack_b);
	ft_lstclear(&stack_a->chunk, free);
	ft_lstclear(&stack_b->chunk, free);
	ft_lstclear(&stack_b->chunk_size, free);
}
