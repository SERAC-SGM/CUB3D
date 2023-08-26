/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:13:59 by mat               #+#    #+#             */
/*   Updated: 2023/08/26 15:21:23 by lletourn         ###   ########.fr       */
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

static int	store_texture(t_map_data *mdata, char *line)
{
	if (!mdata->texture[0] && ft_strncmp(line, "NO ", 3) == 0)
	{
		mdata->texture[0] = trim_path(line);
		return (1);
	}
	else if (!mdata->texture[2] && ft_strncmp(line, "SO ", 3) == 0)
	{
		mdata->texture[2] = trim_path(line);
		return (1);
	}
	else if (!mdata->texture[1] && ft_strncmp(line, "WE ", 3) == 0)
	{
		mdata->texture[1] = trim_path(line);
		return (1);
	}
	else if (!mdata->texture[3] && ft_strncmp(line, "EA ", 3) == 0)
	{
		mdata->texture[3] = trim_path(line);
		return (1);
	}
	else
		return (test_colors(mdata, line));
}

static int	all_params_set(t_map_data *mdata)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mdata->texture[i] == NULL)
			return (0);
		i++;
	}
	if (mdata->color_ceiling == -1 || mdata->color_floor == -1)
		return (0);
	return (1);
}

static int	is_valid_param(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}


int	get_texture_path(t_map_data *mdata)
{
	char	*line;
	int		counter;

	counter = 0;
	while (!all_params_set(mdata))
	{
		line = get_next_line(mdata->map_fd);
		if (line == NULL)
			break ;
		while (line && line[0] == '\n')
		{
			free(line);
			line = get_next_line(mdata->map_fd);
		}
		if (line && is_valid_param(line))
		{
			if (store_texture(mdata, line))
				counter++;
		}
		free(line);
	}
	if (counter != 6)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
