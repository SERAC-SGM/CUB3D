/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:53:01 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_arg(t_arg_spec *spec)
{
	free(spec);
	return ;
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*rst;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	rst = ft_strjoin(s1, s2);
	return (free(s1), free(s2), rst);
}

void	*ft_setalloc(size_t size, char c, int null_terminated)
{
	void	*arr;
	size_t	i;

	arr = malloc(size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
		((char *)arr)[i++] = c;
	if (null_terminated)
		((char *)arr)[size - 1] = 0;
	return (arr);
}

char	*ft_strinsert(char *s, char *to_insert, size_t pos)
{
	char	*rst;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	rst = malloc(len + ft_strlen(to_insert) + 1);
	if (!rst)
		return (NULL);
	i = 0;
	while (i < pos && *s)
		rst[i++] = *s++;
	while (*to_insert)
		rst[i++] = *to_insert++;
	while (*s)
		rst[i++] = *s++;
	rst[i] = 0;
	return (rst);
}

char	*ft_strinsert_free(char *s, char *to_insert, size_t pos)
{
	char	*rst;

	if (!s)
		return (NULL);
	if (!to_insert)
		return (s);
	rst = ft_strinsert(s, to_insert, pos);
	free(s);
	free(to_insert);
	return (rst);
}
