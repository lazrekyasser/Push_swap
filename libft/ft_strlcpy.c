/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:55:07 by ylazrek           #+#    #+#             */
/*   Updated: 2021/05/31 18:09:03 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		lsrc;
	size_t		n;

	d = dst;
	s = src;
	lsrc = ft_strlen(s);
	if (dst == NULL)
		return (lsrc);
	if (size)
	{
		if (lsrc < size - 1)
		{
			n = lsrc;
			ft_memcpy(d, s, n);
		}
		else
		{
			n = size - 1;
			ft_memcpy(d, s, n);
		}
		d[n] = '\0';
	}
	return (lsrc);
}
