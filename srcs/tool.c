/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 08:49:16 by ylazrek           #+#    #+#             */
/*   Updated: 2021/06/25 20:49:17 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_compaire(char *s, char *n)
{
	size_t	i;

	i = 0;
	if (s[0] == '-')
	{
		i++;
	}
	while (i < ft_strlen(n))
	{
		if (s[i] > n[i])
			return (0);
		else if (s[i] < n[i])
			break ;
		i++;
	}
	return (1);
}

int	cas_neg(char *s, int *i, int *cnt_digit)
{
	(*i)++;
	while (s[*i] == '0')
		(*i)++;
	while (s[*i] != '\0')
	{
		if (s[*i] < '0' || s[*i] > '9')
			return (0);
		(*cnt_digit)++;
		(*i)++;
	}
	return (1);
}

int	cas_pos(char *s, int *i, int *cnt_digit, int *plus)
{
	if (s[0] == '+')
	{
		(*i)++;
		(*plus)++;
	}
	while (s[*i] == '0')
		(*i)++;
	while (s[*i] != '\0')
	{
		if (s[*i] < '0' || s[*i] > '9')
			return (0);
		(*cnt_digit)++;
		(*i)++;
	}
	return (1);
}

int	is_num(char *s)
{
	int	i;
	int	cnt_digit;
	int	is_pos;
	int	plus;

	i = 0;
	cnt_digit = 0;
	is_pos = 0;
	plus = 0;
	if (s[0] == '-')
		if (cas_neg(s, &i, &cnt_digit) == 0)
			return (0);
	if (s[0] != '-')
	{
		is_pos = 1;
		if (cas_pos(s, &i, &cnt_digit, &plus) == 0)
			return (0);
	}
	if (cnt_digit > 10)
		return (0);
	else if (cnt_digit == 10 && is_pos == 1)
		return (ft_compaire(&s[plus], "2147483647"));
	else if (cnt_digit == 10 && is_pos == 0)
		return (ft_compaire(s, "-2147483648"));
	return (1);
}

int	stack_dupl(t_stack *a)
{
	int		ret;
	t_list	*tmpi;
	t_list	*tmpj;

	ret = 0;
	tmpi = a->node;
	tmpj = a->node;
	while (tmpi)
	{
		tmpj = a->node;
		while (tmpj)
		{
			if (tmpi != tmpj)
			{
				if (*(int *)tmpi->content == *(int *)tmpj->content)
					return (0);
			}
			tmpj = tmpj->next;
		}
		tmpi = tmpi->next;
	}
	return (1);
}
