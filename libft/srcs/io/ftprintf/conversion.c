/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:45:08 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen_base(long long n, size_t b_size)
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
		n = n / b_size;
		size++;
	}
	return (size);
}

size_t	ft_uintlen_base(unsigned long long n, size_t b_size)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / b_size;
		size++;
	}
	return (size);
}

char	*ft_utoa(unsigned long long n)
{
	char	*nstr;
	size_t	size;

	size = ft_nblen((long long)n);
	nstr = malloc(sizeof(char) * (size + 1));
	if (!nstr)
		return (NULL);
	if (n == 0)
		return (nstr[0] = '0', nstr[1] = '\0', nstr);
	nstr[size--] = '\0';
	while (n > 0)
	{
		nstr[size--] = n % 10 + '0';
		n = n / 10;
	}
	return (nstr);
}

char	*ft_itoa_base(int64_t n, char *base)
{
	char	*nstr;
	size_t	b_size;
	size_t	size;

	b_size = ft_strlen(base);
	size = ft_intlen_base(n, b_size);
	nstr = malloc(sizeof(char) * (size + 1));
	if (!nstr)
		return (NULL);
	if (n == 0)
		return (nstr[0] = base[0], nstr[1] = '\0', nstr);
	if (n < 0)
	{
		n *= -1;
		nstr[0] = '-';
	}
	nstr[size--] = '\0';
	while (n > 0)
	{
		nstr[size--] = base[n % b_size];
		n = n / b_size;
	}
	return (nstr);
}

char	*ft_utoa_base(uint64_t n, char *base)
{
	char	*nstr;
	size_t	b_size;
	size_t	size;

	b_size = ft_strlen(base);
	size = ft_uintlen_base(n, b_size);
	nstr = malloc(sizeof(char) * (size + 1));
	if (!nstr)
		return (NULL);
	if (n == 0)
		return (nstr[0] = base[0], nstr[1] = '\0', nstr);
	nstr[size--] = '\0';
	while (n > 0)
	{
		nstr[size--] = base[n % b_size];
		n = n / b_size;
	}
	return (nstr);
}
