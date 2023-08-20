/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:51:08 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/20 12:47:54 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map(t_map_data *mdata)
{
	int	y;
	int	x;

	y = 0;
	while (y < mdata->map_height)
	{
		x = 0;
		while (x < mdata->map_width)
		{
			mdata->map[y][x] = 9;
			x++;
		}
		y++;
	}
}

static void	fill_map_case(char c, int y, int x, t_data *data)
{
	if (c == ' ')
		data->mdata->map[y][x] = MAP_VOID;
	else if (c == '0')
		data->mdata->map[y][x] = MAP_FLOOR;
	else if (c == '1')
		data->mdata->map[y][x] = MAP_WALL;
	else if (c == '+')
		data->mdata->map[y][x] = get_sprite_pos(y, x, data);
	else if (c == 'D')
		data->mdata->map[y][x] = CLOSED_DOOR;
	else if (c == 'd')
		data->mdata->map[y][x] = OPEN_DOOR;
	else
		data->mdata->map[y][x] = get_player_data(data,
				data->mdata->map_strs->str[x], y, x);
}

static void	fill_map(t_data *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	init_map(data->mdata);
	while (data->mdata->map_strs != NULL)
	{
		x = -1;
		while (data->mdata->map_strs->str[++x] != '\n'
			&& data->mdata->map_strs->str[x] != 0)
			fill_map_case(data->mdata->map_strs->str[x], y, x, data);
		data->mdata->map_strs = data->mdata->map_strs->next;
		y++;
	}
}

static void	get_map_size(t_map_data *mdata)
{
	char		*line;
	int			tmp;

	mdata->map_height = 0;
	mdata->map_width = 0;
	line = get_next_line(mdata->map_fd);
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
	free(line);
}

int	parsing(t_data *data)
{
	if (get_texture_path(data->mdata) == EXIT_FAILURE)
		return (print_error(E_MISSING_TXT));
	if (data->mdata->color_ceiling == -1 || data->mdata->color_floor == -1)
	{
		print_error(E_COLOR);
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
		ft_lstclear(&data->mdata->top, free);
		return (print_error(E_UNCLOSED_MAP));
	}
	if (check_player(data->mdata) == EXIT_FAILURE)
	{
		ft_lstclear(&data->mdata->top, free);
		return (EXIT_FAILURE);
	}
	ft_lstclear(&data->mdata->top, free);
	return (EXIT_SUCCESS);
}
