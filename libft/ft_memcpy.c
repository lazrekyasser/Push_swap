/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:25:25 by ylazrek           #+#    #+#             */
/*   Updated: 2021/05/31 17:58:18 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*strsrc;
	unsigned char	*strdest;

	strsrc = (unsigned char *)src;
	strdest = (unsigned char *)dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (n--)
	{
		*strdest = *strsrc;
		strsrc++;
		strdest++;
	}
	return (dest);
}
