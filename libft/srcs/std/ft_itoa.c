/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:01:24 by maaliber          #+#    #+#             */
/*   Updated: 2023/02/02 15:36:54 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nblen(long long n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{	
	long long	nb;
	char		*nstr;
	size_t		size;

	nb = (long long)n;
	size = ft_nblen(nb);
	nstr = malloc(sizeof(char) * (size + 1));
	if (!nstr)
		return (NULL);
	if (nb == 0)
		return (nstr[0] = '0', nstr[1] = '\0', nstr);
	if (nb < 0)
	{
		nb *= -1;
		nstr[0] = '-';
	}
	nstr[size--] = '\0';
	while (nb > 0)
	{
		nstr[size--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (nstr);
}
