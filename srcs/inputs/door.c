/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:24:17 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/17 14:06:22 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_general_dir(float dir)
{
	if (dir <= -0.5)
		return (-1);
	if (dir < 0.5)
		return (0);
	else
		return (1);
}

void	change_door_state(t_data *data)
{
	const int	general_dirx = get_general_dir(data->player->dirx);
	const int	general_diry = get_general_dir(data->player->diry);
	const int	door_x = (int)data->player->posx + general_dirx;
	const int	door_y = (int)data->player->posy + general_diry;

	if (data->mdata->map[door_x][door_y] == 'd')
		data->mdata->map[door_x][door_y] = 'D';
	else if (data->mdata->map[door_x][door_y] == 'D')
		data->mdata->map[door_x][door_y] = 'd';
}
