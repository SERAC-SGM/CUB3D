/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:20:33 by maaliber          #+#    #+#             */
/*   Updated: 2023/03/20 16:21:26 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*getline_and_trim(char *store)
{
	char	*line;
	size_t	l_line;
	size_t	i;

	l_line = ft_linelen(store);
	if (store[l_line] == '\n')
		l_line++;
	line = malloc(sizeof(char) * l_line + 1);
	if (!line || l_line == 0)
		return (free(line), NULL);
	line[l_line] = 0;
	i = 0;
	while (i < l_line && *store)
		line[i++] = *store++;
	while (*store)
	{
		*(store - l_line) = *store;
		store++;
	}
	*(store - l_line) = 0;
	return (line);
}

char	*getline_and_store(char *store, char *text)
{
	char	*line;
	size_t	l_line;
	size_t	i;

	l_line = ft_linelen(text);
	if (text[l_line] == '\n')
		l_line++;
	line = malloc(sizeof(char) * l_line + 1);
	if (!line || l_line == 0)
		return (free(line), NULL);
	line[l_line] = 0;
	i = 0;
	while (i < l_line && *text)
		line[i++] = *text++;
	while (*text)
		store[i++ - l_line] = *text++;
	store[i - l_line] = 0;
	return (line);
}

char	*read_file(char *store, int fd)
{
	char	*buffer;
	char	*text;
	char	*line;
	ssize_t	rbytes;

	buffer = malloc(BUFFER_SIZE + 1);
	text = malloc(ft_strlen(store) + 1);
	if (!buffer || !text)
		return (free(text), free(buffer), NULL);
	ft_memcpy(text, store, ft_strlen(store) + 1);
	rbytes = 1;
	while (rbytes > 0 && text[ft_linelen(text)] != '\n')
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes == -1)
			break ;
		buffer[rbytes] = 0;
		text = ft_strjoin_gnl(text, buffer);
		if (!text)
			return (free(buffer), NULL);
	}
	line = getline_and_store(store, text);
	return (free(text), free(buffer), line);
}

char	*get_next_line(int fd)
{
	static char	store[BUFFER_SIZE];
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (store[ft_linelen(store)] == '\n')
		line = getline_and_trim(store);
	else
		line = read_file(store, fd);
	if (!line)
		return (NULL);
	return (line);
}
