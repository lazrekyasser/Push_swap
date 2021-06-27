/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:40:47 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/26 19:05:15 by ylazrek          ###   ########.fr       */
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

static void	checke(t_stack *a, t_stack *b)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		check_ins(line, a, b);
		free(line);
		ret = get_next_line(0, &line);
	}
	free(line);
	if (!check_sorted(a) && !b->size)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
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
		checke(&a, &b);
		clear_stacks(&a, &b);
	}
	return (0);
}
