/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:05:35 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/26 18:25:15 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_exit(char **splt_av)
{
	free_tab(splt_av);
	return (1);
}

int	check_arg2(char **splt_av, int *j)
{
	if (ft_lentab(splt_av) == 1)
	{
		if (!is_num(splt_av[0]))
			return (free_exit(splt_av));
	}
	else if (ft_lentab(splt_av) == 0)
		return (free_exit(splt_av));
	else if (ft_lentab(splt_av) > 1)
	{
		*j = 0;
		while (splt_av[*j] != NULL)
		{
			if (!is_num(splt_av[*j]))
				return (free_exit(splt_av));
			(*j)++;
		}
	}
	return (0);
}

int	check_arg(char **av)
{
	int		i;
	int		j;
	char	**splt_av;

	i = 1;
	j = 0;
	splt_av = NULL;
	while (av[i] != NULL)
	{
		splt_av = ft_split(av[i], ' ');
		if (check_arg2(splt_av, &j) == 1)
			return (1);
		free_tab(splt_av);
		i++;
	}
	return (0);
}

void	raise_error(t_list *node, char **tab)
{
	t_list	*tmp;

	ft_putendl_fd("Error", 2);
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp->content);
		free(tmp);
	}
	if (tab)
		free_tab(tab);
	exit(1);
}
