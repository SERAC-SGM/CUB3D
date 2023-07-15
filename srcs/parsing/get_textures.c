/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:13:59 by mat               #+#    #+#             */
/*   Updated: 2023/07/15 18:16:02 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*trim_path(char *line)
{
	char	*path;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (line[i] != '.')
		i++;
	while (line[i])
	{
		i++;
		len++;
	}
	path = malloc(sizeof(char) * (len));
	i = i - len;
	len = 0;
	while (line[i] != '\n')
		path[len++] = line[i++];
	path[len] = '\0';
	return (path);
}


static void	store_texture(t_map_data *mdata, char *line, int *counter)
{
	if (ft_strncmp(line, "NO .", 4) == 0)
	{
		(*counter)++;
		mdata->path_texture_n = trim_path(line);
	}
	else if (ft_strncmp(line, "SO .", 4) == 0)
	{
		(*counter)++;
		mdata->path_texture_s = trim_path(line);
	}
	else if (ft_strncmp(line, "WE .", 4) == 0)
	{
		(*counter)++;
		mdata->path_texture_w = trim_path(line);
	}
	else if (ft_strncmp(line, "EA .", 4) == 0)
	{
		(*counter)++;
		mdata->path_texture_e = trim_path(line);
	}
	else
	{
		test_colors(mdata, line, counter);
	}
}

void	get_texture_path(t_map_data *mdata)
{
	char	*line;
	int		counter;

	counter = 0;
	while (counter < 6)
	{
		line = get_next_line(mdata->map_fd);
		if (line == NULL)
			break ;
		while (line[0] == '\n')
		{
			free(line);
			line = get_next_line(mdata->map_fd);
		}
		store_texture(mdata, line, &counter);
		free(line);
	}
	return ;
}
