/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:38:48 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/17 11:13:45 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_distances(t_ray *ray, t_player *player)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (player->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - player->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (player->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - player->posy) * ray->deltadisty;
	}
}

/*
*		DDA algorithm
*/
static void	check_hit(t_ray *ray, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			if (ray->stepx == 1)
				ray->side = 0;
			else if (ray->stepx == -1)
				ray->side = 2;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			if (ray->stepy == 1)
				ray->side = 1;
			else if (ray->stepy == -1)
				ray->side = 3;
		}
		if (data->mdata->map[ray->mapx][ray->mapy] > 0)
			ray->hit = 1;
	}
}

static void	get_wall_heigth(t_ray *ray, t_player *player, t_data *data)
{
	if (ray->side == 0 || ray->side == 2)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
	ray->lineheight = WIN_HEIGHT / ray->perpwalldist;
	ray->drawstart = -ray->lineheight / 2 + WIN_HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + WIN_HEIGHT / 2;
	if (ray->drawend >= WIN_HEIGHT)
		ray->drawend = WIN_HEIGHT - 1;
	ray->wallx = 0;
	if (ray->side == 0 || ray->side == 2)
		ray->wallx = player->posy + ray->perpwalldist * ray->raydiry;
	else
		ray->wallx = player->posx + ray->perpwalldist * ray->raydirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)data->texture[0].width);
	if (((ray->side == 0 || ray->side == 2) && ray->raydirx > 0))
		ray->texx = data->texture[0].width - ray->texx - 1;
	if (((ray->side == 1 || ray->side == 3) && ray->raydiry < 0))
		ray->texx = data->texture[0].width - ray->texx - 1;
	ray->step = 1.0 * data->texture[0].height / ray->lineheight;
	ray->texpos = (ray->drawstart - WIN_HEIGHT / 2 + ray->lineheight / 2)
		* ray->step;
}

static void	display_line(int x, t_ray *ray, t_data *data)
{
	int	y;

	y = -1;
	while (++y < ray->drawstart)
		pixel_put_in_image(&data->img, x, y, data->mdata->color_c);
	while (++y < ray->drawend)
		put_texture_pixel(ray, data, x, y);
	while (++y < WIN_HEIGHT)
		pixel_put_in_image(&data->img, x, y, data->mdata->color_f);
}

void	raycasting(t_data	*data)
{
	int			x;
	t_player	player;
	t_ray		ray;

	player = *data->player;
	ray = data->ray;
	x = -1;
	while (++x < WIN_WIDTH)
	{
		ray.camerax = 2 * x / (double)WIN_WIDTH - 1;
		ray.raydirx = player.dirx + player.planex * ray.camerax;
		ray.raydiry = player.diry + player.planey * ray.camerax;
		ray.mapx = player.posx;
		ray.mapy = player.posy;
		ray.deltadistx = fabs(1 / ray.raydirx);
		ray.deltadisty = fabs(1 / ray.raydiry);
		ray.hit = 0;
		get_distances(&ray, &player);
		check_hit(&ray, data);
		get_wall_heigth(&ray, &player, data);
		display_line(x, &ray, data);
		data->ray = ray;
	}
}
