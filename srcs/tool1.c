/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:55:08 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/22 17:48:40 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*alloc_size(int size)
{
	int	*i;

	i = malloc(sizeof(int));
	*i = size;
	return (i);
}

int	*list_to_tab(t_list *lst)
{
	t_list	*tmp;
	int		*tab;
	int		i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * ft_lstsize(lst));
	tmp = lst;
	while (tmp)
	{
		tab[i] = *(int *)tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

int	ft_lentab(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	affiche_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putendl_fd(s[i], 1);
		i++;
	}
}
