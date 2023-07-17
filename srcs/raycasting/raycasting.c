/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:38:48 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/14 15:39:21 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	encode_rgb(__uint8_t red, __uint8_t green, __uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	pixel_put_in_image(t_image *image, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = image->bits_per_pixel - 8;
	pixel = image->address + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (image->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (image->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}
// int	get_color(t_data *data)
// {
// 	if (data->mdata->map[data->ray.mapx][data->ray.mapy] == 1)
// 		return (encode_rgb(255, 0, 0));
// 	if (data->mdata->map[data->ray.mapx][data->ray.mapy] == 2)
// 		return (encode_rgb(0, 255, 0));
// 	if (data->mdata->map[data->ray.mapx][data->ray.mapy] == 3)
// 		return (encode_rgb(0, 0, 255));
// 	if (data->mdata->map[data->ray.mapx][data->ray.mapy] == 4)
// 		return (encode_rgb(255, 255, 255));
// 	else
// 		return (encode_rgb(127, 127, 127));
// }

void	draw_line(int x, t_data *data)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < data->ray.drawstart)
			pixel_put_in_image(&data->img, x, y, encode_rgb(0, 0, 0));
		else if (y >= data->ray.drawstart && y <= data->ray.drawend)
			pixel_put_in_image(&data->img, x, y, data->TEMPCOLOR);
		else if (y > data->ray.drawend)
			pixel_put_in_image(&data->img, x, y, encode_rgb(50, 50, 50));
	}
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
		if (ray.raydirx < 0)
		{
			ray.stepx = -1;
			ray.sidedistx = (player.posx - ray.mapx) * ray.deltadistx;
		}
		else
		{
			ray.stepx = 1;
			ray.sidedistx = (ray.mapx + 1.0 - player.posx) * ray.deltadistx;
		}
		if (ray.raydiry < 0)
		{
			ray.stepy = -1;
			ray.sidedisty = (player.posy - ray.mapy) * ray.deltadisty;
		}
		else
		{
			ray.stepy = 1;
			ray.sidedisty = (ray.mapy + 1.0 - player.posy) * ray.deltadisty;
		}
		while (ray.hit == 0)
		{
			if (ray.sidedistx < ray.sidedisty)
			{
				ray.sidedistx += ray.deltadistx;
				ray.mapx += ray.stepx;
				if (ray.stepx == 1)
					ray.side = 2;
				else if (ray.stepx == -1)
					ray.side = 0;
			}
			else
			{
				ray.sidedisty += ray.deltadisty;
				ray.mapy += ray.stepy;
				if (ray.stepy == 1)
					ray.side = 3;
				else if (ray.stepy == -1)
					ray.side = 1;
			}
			if (data->mdata->map[ray.mapx][ray.mapy] > 0)
				ray.hit = 1;
		}
		if (ray.side == 0 || ray.side == 2)
			ray.perpwalldist = (ray.sidedistx - ray.deltadistx);
		else
			ray.perpwalldist = (ray.sidedisty - ray.deltadisty);
		ray.lineheight = WIN_HEIGHT / ray.perpwalldist;
		ray.drawstart = -ray.lineheight / 2 + WIN_HEIGHT / 2;
		if (ray.drawstart < 0)
			ray.drawstart = 0;
		ray.drawend = ray.lineheight / 2 + WIN_HEIGHT / 2;
		if (ray.drawend >= WIN_HEIGHT)
			ray.drawend = WIN_HEIGHT - 1;
		data->ray = ray;
		if (ray.side == 0)
			data->TEMPCOLOR = encode_rgb(255, 0, 0);
		else if (ray.side == 1)
			data->TEMPCOLOR = encode_rgb(0, 255, 0);
		else if (ray.side == 2)
			data->TEMPCOLOR = encode_rgb(0, 0, 255);
		else
			data->TEMPCOLOR = encode_rgb(255, 255, 255);
		draw_line(x, data);
	}
}