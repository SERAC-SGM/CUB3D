/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:56:28 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/14 14:04:08 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_player_data(t_data *data, char c, int i, int j)
{
	data->player->posx = i;
	data->player->posy = j;
	data->player->planex = 0;
	data->player->planey = 0.66;
	if (c == 'N')
	{
		data->player->dirx = 0;
		data->player->diry = 1;
	}
	else if (c == 'S')
	{
		data->player->dirx = 0;
		data->player->diry = -1;
	}
	else if (c == 'E')
	{
		data->player->dirx = 1;
		data->player->diry = 0;
	}
	else if (c == 'W')
	{
		data->player->dirx = -1;
		data->player->diry = 0;
	}
	return (MAP_FLOOR);
}