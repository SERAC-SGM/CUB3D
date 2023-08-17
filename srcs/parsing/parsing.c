/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:51:08 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/16 12:11:30 by lletourn         ###   ########.fr       */
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

static void	fill_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	init_map(data->mdata);
	while (data->mdata->map_strs != NULL)
	{
		j = -1;
		while (data->mdata->map_strs->str[++j] != '\n')
		{
			if (data->mdata->map_strs->str[j] == ' ')
				data->mdata->map[i][j] = MAP_VOID;
			else if (data->mdata->map_strs->str[j] == '0')
				data->mdata->map[i][j] = MAP_FLOOR;
			else if (data->mdata->map_strs->str[j] == '1')
				data->mdata->map[i][j] = MAP_WALL;
			else if (data->mdata->map_strs->str[j] == '+')
				data->mdata->map[i][j] = get_sprite_pos(i, j, data);
			else
				data->mdata->map[i][j] = get_player_and_door_data(data,
						data->mdata->map_strs->str[j], i, j);
			//j++;
		}
		data->mdata->map_strs = data->mdata->map_strs->next;
		i++;
	}
}

static char	*get_first_lst_ptr(t_map_data *mdata, char *line, int *tmp)
{
	ft_lstadd_back(&mdata->map_strs, ft_lstnew(ft_strdup(line)));
	mdata->map_height++;
	*tmp = ft_strlen(line);
	if (*tmp - 1 > mdata->map_width)
		mdata->map_width = *tmp - 1;
	free(line);
	line = get_next_line(mdata->map_fd);
	mdata->top = mdata->map_strs;
	return (line);
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
		return (EXIT_FAILURE);
	}
	get_map_size(data->mdata);
	if (malloc_structs(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fill_map(data);
	if (check_player(data->mdata) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_map(data) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(E_UNCLOSED_MAP, 2);
		return (EXIT_FAILURE);
	}
	ft_lstclear(&data->mdata->top, free);
	//printf("data sprite nb %d\n", data->sprite_number);
	return (EXIT_SUCCESS);
}
