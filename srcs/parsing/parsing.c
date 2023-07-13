/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:51:08 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/13 15:22:21 by mat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_player_orientation(char c)
{
	if (c == 'N')
		return (PLAYER_NORTH);
	else if (c == 'S')
		return (PLAYER_SOUTH);
	else if (c == 'E')
		return (PLAYER_EAST);
	else if (c == 'W')
		return (PLAYER_WEST);
	return (MAP_VOID);
}

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

static void	fill_map(t_map_data *mdata)
{
	size_t	i;
	size_t	j;

	i = 0;
	init_map(mdata);
	while (mdata->map_strs != NULL)
	{
		j = 0;
		while (mdata->map_strs->str[j] != '\n')
		{
			if (mdata->map_strs->str[j] == ' ')
				mdata->map[i][j] = MAP_VOID;
			else if (mdata->map_strs->str[j] == '0')
				mdata->map[i][j] = MAP_FLOOR;
			else if (mdata->map_strs->str[j] == '1')
				mdata->map[i][j] = MAP_WALL;
			else
				mdata->map[i][j] = 
					get_player_orientation(mdata->map_strs->str[j]);
			j++;
		}
		mdata->map_strs = mdata->map_strs->next;
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

void	get_map_data(t_map_data *mdata)
{
	int		i;

	i = 0;
	get_texture_path(mdata);
	printf("NO is %s\n", mdata->path_texture_n);
	printf("SO is %s\n", mdata->path_texture_s);
	printf("WE is %s\n", mdata->path_texture_w);
	printf("EA is %s\n", mdata->path_texture_e);
	printf("F is %d\n", mdata->color_f);
	printf("C is %d\n", mdata->color_c);
	get_map_size(mdata);
	printf("map height is %d\n", mdata->map_height);
	printf("map width is %d\n", mdata->map_width);
	mdata->map = malloc(sizeof(int *) * mdata->map_height);
	while (i < mdata->map_height)
		mdata->map[i++] = malloc(sizeof(int) * mdata->map_width);
	fill_map(mdata);
}
