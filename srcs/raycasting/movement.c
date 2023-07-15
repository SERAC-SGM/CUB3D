/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:51:04 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/15 18:47:13 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_player_side(t_data *data)
{
	if (data->move_right == 1)
	{
		if (data->mdata->map[(int)(data->player->posx
				+ (data->player->diry * MOVE_SPEED * 2))]
						[(int)data->player->posy] == 0)
			data->player->posx += data->player->diry * MOVE_SPEED;
		if (data->mdata->map[(int)data->player->posx][(int)(data->player->posy
			- (data->player->dirx * MOVE_SPEED * 2))] == 0)
			data->player->posy -= data->player->dirx * MOVE_SPEED;
	}
	if (data->move_left == 1)
	{
		if (data->mdata->map[(int)(data->player->posx
				- (data->player->diry * MOVE_SPEED * 2))]
					[(int)data->player->posy] == 0)
			data->player->posx -= data->player->diry * MOVE_SPEED;
		if (data->mdata->map[(int)data->player->posx][(int)(data->player->posy
			+ (data->player->dirx * MOVE_SPEED * 2))] == 0)
			data->player->posy += data->player->dirx * MOVE_SPEED;
	}
}


void	move_player(t_data *data)
{
	if (data->move_fwd == 1)
	{
		if (data->mdata->map[(int)(data->player->posx
				+ (data->player->dirx * MOVE_SPEED * 5))]
					[(int)data->player->posy] == 0)
			data->player->posx += data->player->dirx * MOVE_SPEED;
		if (data->mdata->map[(int)data->player->posx][(int)(data->player->posy
			+ (data->player->diry * MOVE_SPEED * 5))] == 0)
			data->player->posy += data->player->diry * MOVE_SPEED;
	}
	if (data->move_bckwd == 1)
	{
		if (data->mdata->map[(int)(data->player->posx
				- (data->player->dirx * MOVE_SPEED * 2))]
				[(int)data->player->posy] == 0)
			data->player->posx -= data->player->dirx * MOVE_SPEED;
		if (data->mdata->map[(int)data->player->posx][(int)(data->player->posy
			- (data->player->diry * MOVE_SPEED * 2))] == 0)
			data->player->posy -= data->player->diry * MOVE_SPEED;
	}
	move_player_side(data);
}

static void	rotate_player_right(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->player->dirx;
	old_planex = data->player->planex;
	if (data->rotate_right == 1)
	{
		data->player->dirx = old_dirx * cos(-ROTATE_SPEED / 2)
			- data->player->diry * sin(-ROTATE_SPEED / 2);
		data->player->diry = old_dirx * sin(-ROTATE_SPEED / 2)
			+ data->player->diry * cos(-ROTATE_SPEED / 2);
		data->player->planex = old_planex * cos(-ROTATE_SPEED / 2)
			- data->player->planey * sin(-ROTATE_SPEED / 2);
		data->player->planey = old_planex * sin(-ROTATE_SPEED / 2)
			+ data->player->planey * cos(-ROTATE_SPEED / 2);
	}
}

void	rotate_player_left(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->player->dirx;
	old_planex = data->player->planex;
	if (data->rotate_left == 1)
	{
		data->player->dirx = old_dirx * cos(ROTATE_SPEED / 2)
			- data->player->diry * sin(ROTATE_SPEED / 2);
		data->player->diry = old_dirx * sin(ROTATE_SPEED / 2)
			+ data->player->diry * cos(ROTATE_SPEED / 2);
		data->player->planex = old_planex * cos(ROTATE_SPEED / 2)
			- data->player->planey * sin(ROTATE_SPEED / 2);
		data->player->planey = old_planex * sin(ROTATE_SPEED / 2)
			+ data->player->planey * cos(ROTATE_SPEED / 2);
	}
	rotate_player_right(data);
}
