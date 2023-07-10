/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:00:22 by maaliber          #+#    #+#             */
/*   Updated: 2023/02/02 15:36:54 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nstr)
{
	int		n;
	int		s;

	n = 0;
	s = 1;
	while (ft_isspace(*nstr))
		nstr++;
	if (*nstr == '+' || *nstr == '-')
	{
		if (*nstr == '-')
			s = -1;
		nstr++;
	}
	while (*nstr >= '0' && *nstr <= '9')
		n = n * 10 + s * (*nstr++ - '0');
	return (n);
}
