/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:26:38 by ylazrek           #+#    #+#             */
/*   Updated: 2021/05/31 18:08:43 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*ptr;

	if (dst == NULL)
		return (NULL);
	ptr = dst + ft_strlen(dst);
	while (n-- && *src)
	{
		*ptr = *src;
		src++;
		ptr++;
	}
	*ptr = '\0';
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;

	lsrc = ft_strlen(src);
	if (!dst && size == 0)
		return (lsrc);
	ldst = ft_strlen(dst);
	if (ldst >= size)
		return (size + lsrc);
	else
	{
		ft_strncat(dst, src, size - ldst - 1);
		return (ldst + lsrc);
	}
}
