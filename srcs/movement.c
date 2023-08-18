/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:51:04 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/17 16:50:14 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_player_side(t_data *data)
{
	const double	posx = data->player->posx;
	const double	posy = data->player->posy;
	const double	movx = data->player->dirx * MOVE_SPEED;
	const double	movy = data->player->diry * MOVE_SPEED;

	if (data->move_right == 1)
	{
		if (data->mdata->map[(int)(posx + (movy * 2))][(int)posy] == 0
			|| data->mdata->map[(int)(posx + (movy * 2))][(int)posy] == 'd')
			data->player->posx += movy;
		if (data->mdata->map[(int)posx][(int)(posy - (movx * 2))] == 0
			|| data->mdata->map[(int)posx][(int)(posy - (movx * 2))] == 'd')
			data->player->posy -= movx;
	}
	if (data->move_left == 1)
	{
		if (data->mdata->map[(int)(posx - (movy * 2))][(int)posy] == 0
			|| data->mdata->map[(int)(posx - (movy * 2))][(int)posy] == 'd')
			data->player->posx -= movy;
		if (data->mdata->map[(int)posx][(int)(posy + (movx * 2))] == 0
			|| data->mdata->map[(int)posx][(int)(posy + (movx * 2))] == 'd')
			data->player->posy += movx;
	}
}

void	move_player(t_data *data)
{
	const double	posx = data->player->posx;
	const double	posy = data->player->posy;
	const double	movx = data->player->dirx * MOVE_SPEED;
	const double	movy = data->player->diry * MOVE_SPEED;

	if (data->move_fwd == 1)
	{
		if (data->mdata->map[(int)(posx + (movx * 5))][(int)posy] == 0
			|| data->mdata->map[(int)(posx + (movx * 5))][(int)posy] == 'd')
			data->player->posx += movx;
		if (data->mdata->map[(int)posx][(int)(posy + (movy * 5))] == 0
			|| data->mdata->map[(int)posx][(int)(posy + (movy * 5))] == 'd')
			data->player->posy += movy;
	}
	if (data->move_bckwd == 1)
	{
		if (data->mdata->map[(int)(posx - (movx * 2))][(int)posy] == 0
			|| data->mdata->map[(int)(posx - (movx * 2))][(int)posy] == 'd')
			data->player->posx -= movx;
		if (data->mdata->map[(int)posx][(int)(posy - (movy * 2))] == 0
			|| data->mdata->map[(int)posx][(int)(posy - (movy * 2))] == 'd')
			data->player->posy -= movy;
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
