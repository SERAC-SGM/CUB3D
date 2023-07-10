/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:02:35 by maaliber          #+#    #+#             */
/*   Updated: 2023/05/09 16:07:45 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rst;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	rst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rst)
		return (NULL);
	i = 0;
	while (*s1)
		rst[i++] = *s1++;
	while (*s2)
		rst[i++] = *s2++;
	rst[i] = '\0';
	return (rst);
}
