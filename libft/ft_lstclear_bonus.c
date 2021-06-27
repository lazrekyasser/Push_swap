/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:58:33 by ylazrek           #+#    #+#             */
/*   Updated: 2021/05/31 17:49:00 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*prec;

	tmp = *lst;
	while (tmp != NULL)
	{
		del(tmp->content);
		prec = tmp;
		tmp = tmp->next;
		free(prec);
	}
	*lst = NULL;
}
