/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:00:18 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/22 18:49:40 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max(int *t)
{
	int	max;
	int	i;
	int	ret;

	max = t[0];
	i = 1;
	ret = 0;
	while (i < 3)
	{
		if (t[i] > max)
		{
			max = t[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

static int	check_top2(t_stack *a)
{
	if (*(int *)a->node->content > *(int *)a->node->next->content)
		return (1);
	return (0);
}

static void	cas_s0(t_stack *a, t_stack *b)
{
	exec_ins("ra", a, b);
	if (check_top2(a) == 1)
	{
		exec_ins("sa", a, b);
		ft_putendl_fd("sa", 1);
	}
}

void	sort_stack3(t_stack *a, t_stack *b)
{
	int	*tab;
	int	index_max;

	tab = list_to_tab(a->node);
	index_max = get_max(tab);
	if (index_max == 0)
		cas_s0(a, b);
	else if (index_max == 1)
	{
		exec_ins("rra", a, b);
		if (check_top2(a) == 1)
		{
			exec_ins("sa", a, b);
			ft_putendl_fd("sa", 1);
		}
	}
	else if (index_max == 2)
	{
		if (check_top2(a) == 1)
		{
			exec_ins("sa", a, b);
			ft_putendl_fd("sa", 1);
		}
	}
	free(tab);
}
