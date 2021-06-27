/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:25:40 by ylazrek           #+#    #+#             */
/*   Updated: 2021/05/31 18:12:54 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chrc(char const *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	k = 0;
	if (s1 == NULL)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[++i] != '\0')
		if (!ft_chrc(set, s1[i]))
			break ;
	while (j--)
		if (!ft_chrc(set, s1[j]))
			break ;
	if (i == ft_strlen(s1) || j == 0)
		return (ft_strdup("\0"));
	str = (char *)malloc(j - i + 2);
	if (!str)
		return (NULL);
	while (i <= j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
