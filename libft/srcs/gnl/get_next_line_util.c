/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:20:33 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/20 16:19:31 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_linelen(char *txt)
{
	size_t	i;

	i = 0;
	if (!txt)
		return (0);
	while (txt[i] != '\n' && txt[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *txt, char *add)
{
	char	*arr;
	size_t	i;
	size_t	l;

	if (!txt || !add)
		return (NULL);
	l = ft_strlen(txt) + ft_strlen(add);
	arr = malloc(sizeof(char) * l + 1);
	if (!arr)
		return (free(txt), NULL);
	i = 0;
	while (txt[i])
	{
		arr[i] = txt[i];
		i++;
	}
	while (*add)
		arr[i++] = *add++;
	arr[i] = 0;
	free(txt);
	return (arr);
}
