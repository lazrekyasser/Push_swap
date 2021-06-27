/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:02:52 by yasser            #+#    #+#             */
/*   Updated: 2021/06/26 19:06:00 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	remplire_stack(t_stack *a, char **av)
{
	int		i;
	int		j;
	char	**splt_av;

	i = ft_lentab(av) - 1;
	j = ft_lentab(av) - 1;
	splt_av = NULL;
	while (i > 0)
	{
		splt_av = ft_split(av[i], ' ');
		j = ft_lentab(splt_av) - 1;
		while (j >= 0)
		{
			if (!is_num(splt_av[j]))
			{
				free_tab(splt_av);
				return (1);
			}
			push(a, ft_atoi(splt_av[j]));
			j--;
		}
		free_tab(splt_av);
		i--;
	}
	return (0);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		sort_stack3(a, b);
	else
		sort_stack(a, b);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac > 1)
	{
		stack_new(&a);
		init_stackb(&b);
		if (check_arg(av) == 1)
			print_error("ERROR\n", NULL, NULL);
		if (remplire_stack(&a, av) == 1)
			print_error("ERROR\n", &a, &b);
		if (stack_dupl(&a) == 0)
			print_error("ERROR\n", &a, &b);
		if (!check_sorted(&a))
		{
			clear_stacks(&a, &b);
			return (0);
		}
		sort(&a, &b);
		clear_stacks(&a, &b);
	}
	return (0);
}
