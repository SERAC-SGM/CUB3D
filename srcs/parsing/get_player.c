/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:56:28 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/15 20:50:00 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_player_data_sides(t_data *data, char c)
{
	if (c == 'E')
	{
		data->player->planex = 0.66;
		data->player->planey = 0;
		data->player->dirx = 0;
		data->player->diry = 1;
	}
	else if (c == 'W')
	{
		data->player->planex = -0.66;
		data->player->planey = 0;
		data->player->dirx = 0;
		data->player->diry = -1;
	}
	return (MAP_FLOOR);
}

int	get_player_data(t_data *data, char c, int i, int j)
{
	data->player->posx = i + 0.5;
	data->player->posy = j + 0.5;
	data->player->planex = 0;
	data->player->planey = 0.66;
	if (c == 'N')
	{
		data->player->planex = 0;
		data->player->planey = 0.66;
		data->player->dirx = -1;
		data->player->diry = 0;
	}
	else if (c == 'S')
	{
		data->player->planex = 0;
		data->player->planey = -0.66;
		data->player->dirx = 1;
		data->player->diry = 0;
	}
	else
		return (get_player_data_sides(data, c));
	return (MAP_FLOOR);
}
