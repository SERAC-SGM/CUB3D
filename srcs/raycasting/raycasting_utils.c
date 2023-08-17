/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:48:53 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/17 10:50:20 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	encode_rgb(__uint8_t red, __uint8_t green, __uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	init_ray(int x, t_ray *ray, t_player *player)
{
	ray->camerax = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydirx = player->dirx + player->planex * ray->camerax;
	ray->raydiry = player->diry + player->planey * ray->camerax;
	ray->mapx = player->posx;
	ray->mapy = player->posy;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	ray->hit = 0;
}

void	check_door_inside_hit(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
	{
		if (ray->mapx >= 1 && data->mdata->map[ray->mapx - 1][ray->mapy] == 'd')
			ray->side = 6;
	}
	else if (ray->side == 1)
	{
		if (ray->mapy >= 1 && data->mdata->map[ray->mapx][ray->mapy - 1] == 'd')
			ray->side = 7;
	}
	else if (ray->side == 2)
	{
		if (ray->mapx + 1 <= data->mdata->map_height
			&& data->mdata->map[ray->mapx + 1][ray->mapy] == 'd')
			ray->side = 6;
	}
	else if (ray->side == 3)
	{
		if (ray->mapy + 1 <= data->mdata->map_width
			&& data->mdata->map[ray->mapx][ray->mapy + 1] == 'd')
			ray->side = 7;
	}
}

void	check_door_hit(t_ray *ray)
{
	if (ray->hit == 'D')
	{
		if (ray->side == 0 || ray->side == 2)
			ray->side = 4;
		else
			ray->side = 5;
	}
}
