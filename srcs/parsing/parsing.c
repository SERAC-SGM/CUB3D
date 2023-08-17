/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:51:08 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/17 14:31:33 by mdorr            ###   ########.fr       */
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
			mdata->map[i][j] = 9;
			j++;
		}
		i++;
	}
}

static void	fill_map_case(char c, int i, int j, t_data *data)
{
	if (c == ' ')
		data->mdata->map[i][j] = MAP_VOID;
	else if (c == '0')
		data->mdata->map[i][j] = MAP_FLOOR;
	else if (c == '1')
		data->mdata->map[i][j] = MAP_WALL;
	else if (c == '+')
		data->mdata->map[i][j] = get_sprite_pos(i, j, data);
	else
		data->mdata->map[i][j] = get_player_and_door_data(data,
				data->mdata->map_strs->str[j], i, j);
}

static void	fill_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	init_map(data->mdata);
	while (data->mdata->map_strs != NULL)
	{
		j = -1;
		while (data->mdata->map_strs->str[++j] != '\n'
			&& data->mdata->map_strs->str[j] != 0)
			fill_map_case(data->mdata->map_strs->str[j], i, j, data);
		data->mdata->map_strs = data->mdata->map_strs->next;
		i++;
	}
}


static void	get_map_size(t_map_data *mdata)
{
	char		*line;
	int			tmp;

	mdata->map_height = 0;
	mdata->map_width = 0;
	line = get_next_line(mdata->map_fd);
	mdata->map_strs = NULL;
	while (line != NULL && line[0] != '0' && line[0] != '1' && line[0] != ' ')
	{
		free(line);
		line = get_next_line(mdata->map_fd);
	}
	if (line != NULL && (line[0] == '0' || line[0] == '1' || line[0] == ' '))
		line = get_first_lst_ptr(mdata, line, &tmp);
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

int	parsing(t_data *data)
{
	get_texture_path(data->mdata);
	if (data->mdata->color_ceiling == -1 || data->mdata->color_floor == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(E_COLOR, 2);
		exit_parsing(data);
	}
	get_map_size(data->mdata);
	if (check_map_char(data->mdata) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (malloc_structs(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fill_map(data);
	if (check_map(data) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(E_UNCLOSED_MAP, 2);
		return (EXIT_FAILURE);
	}
	if (check_player(data->mdata) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_lstclear(&data->mdata->top, free);
	return (EXIT_SUCCESS);
}
