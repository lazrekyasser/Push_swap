/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:27:01 by ylazrek           #+#    #+#             */
/*   Updated: 2019/11/04 11:52:23 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*strsrc;
	unsigned char	*strdest;
	size_t			i;

	strsrc = (unsigned char *)src;
	strdest = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	i = (strdest - strsrc);
	if (i > 0 && i < n)
	{
		while (n--)
		{
			*(strdest + n) = *(strsrc + n);
		}
		return (dest);
	}
	else
	{
		ft_memcpy(strdest, strsrc, n);
		return (dest);
	}
	return (NULL);
}
