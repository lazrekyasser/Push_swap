/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:23:50 by ylazrek           #+#    #+#             */
/*   Updated: 2021/05/31 17:47:43 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lentnbr(int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static void	assigne(int *n, int *k)
{
	*n = -1 * (*n);
	*k = 1;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		k;

	k = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		assigne(&n, &k);
	i = ft_lentnbr(n);
	str = (char *)malloc(i + k + 1);
	if (!str)
		return (NULL);
	str[i + k] = '\0';
	if (k == 1)
		str[0] = '-';
	while (n != 0)
	{
		str[i + k - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
