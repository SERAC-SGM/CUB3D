/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:51:08 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/14 14:26:29 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map(t_map_data *mdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mdata->map_height)
	{
		j = 0;
		while (j < mdata->map_width)
		{
			mdata->map[i][j] = 6;
			j++;
		}
		i++;
	}
}

static void	fill_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	init_map(data->mdata);
	while (data->mdata->map_strs != NULL)
	{
		j = 0;
		while (data->mdata->map_strs->str[j] != '\n')
		{
			if (data->mdata->map_strs->str[j] == ' ')
				data->mdata->map[i][j] = MAP_VOID;
			else if (data->mdata->map_strs->str[j] == '0')
				data->mdata->map[i][j] = MAP_FLOOR;
			else if (data->mdata->map_strs->str[j] == '1')
				data->mdata->map[i][j] = MAP_WALL;
			else
				data->mdata->map[i][j] =
					get_player_data(data, data->mdata->map_strs->str[j], i, j);
			j++;
		}
		data->mdata->map_strs = data->mdata->map_strs->next;
		i++;
	}
}

static void	get_map_size(t_map_data *mdata)
{
	char	*line;
	int		tmp;

	mdata->map_height = 0;
	mdata->map_width = 0;
	line = get_next_line(mdata->map_fd);
	mdata->map_strs = NULL;
	while (line != NULL && line[0] != '0' && line[0] != '1' && line[0] != ' ')
	{
		free(line);
		line = get_next_line(mdata->map_fd);
	}
	while (line != NULL && (line[0] == '0' || line[0] == '1' || line[0] == ' '))
	{
		ft_lstadd_back(&mdata->map_strs, ft_lstnew(ft_strdup(line)));
		mdata->map_height++;
		tmp = ft_strlen(line);
		if (tmp - 1 > mdata->map_width)
			mdata->map_width = tmp - 1;
		free(line);
		line = get_next_line(mdata->map_fd);
	}
}

int	get_map_data(t_data *data)
{
	get_texture_path(data->mdata);
	get_map_size(data->mdata);
	printf("F is %d\n", data->mdata->color_f);
	printf("C is %d\n", data->mdata->color_c);
	printf("NO is %s\n", data->mdata->path_texture_n);
	printf("SO is %s\n", data->mdata->path_texture_s);
	printf("WE is %s\n", data->mdata->path_texture_w);
	printf("EA is %s\n", data->mdata->path_texture_e);
	if (malloc_structs(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fill_map(data);
	return (EXIT_SUCCESS);
}