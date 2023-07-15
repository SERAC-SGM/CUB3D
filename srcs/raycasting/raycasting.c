/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:38:48 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/15 19:35:11 by lletourn         ###   ########.fr       */
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

void	draw_line(int x, t_data *data)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < data->ray.drawstart)
			pixel_put_in_image(&data->img, x, y, encode_rgb(0, 0, 0));
		else if (y >= data->ray.drawstart && y <= data->ray.drawend)
			pixel_put_in_image(&data->img, x, y, data->color);
		else if (y > data->ray.drawend)
			pixel_put_in_image(&data->img, x, y, encode_rgb(50, 50, 50));
	}
}

void	raycasting(t_data	*data)
{
	int			x;
	int			y;
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
					ray.side = 0;
				else if (ray.stepx == -1)
					ray.side = 2;
			}
			else
			{
				ray.sidedisty += ray.deltadisty;
				ray.mapy += ray.stepy;
				if (ray.stepy == 1)
					ray.side = 1;
				else if (ray.stepy == -1)
					ray.side = 3;
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
		ray.wallx = 0;
		if (ray.side == 0 || ray.side == 2)
			ray.wallx = player.posy + ray.perpwalldist * ray.raydiry;
		else
			ray.wallx = player.posx + ray.perpwalldist * ray.raydirx;
		ray.wallx -= floor(ray.wallx);
		ray.texx = (int)(ray.wallx * (double)data->texture[0].width);
		if (((ray.side == 0 || ray.side == 2) && ray.raydirx > 0))
			ray.texx = data->texture[0].width - ray.texx - 1;
		if (((ray.side == 1 || ray.side == 3) && ray.raydiry < 0))
			ray.texx = data->texture[0].width - ray.texx - 1;
		ray.step = 1.0 * data->texture[0].height / ray.lineheight;
		ray.texpos = (ray.drawstart - WIN_HEIGHT / 2 + ray.lineheight / 2) * ray.step;
		y = -1;
		while (++y < ray.drawstart)
			pixel_put_in_image(&data->img, x, y, encode_rgb(0, 0, 0));
		while (++y < ray.drawend)
		{
			ray.texy = (int)ray.texpos & (data->texture[0].height - 1);
			ray.texpos += ray.step;
			if (ray.side == 0)
				data->color = data->texture[0].address[ray.texy * (data->texture[0].line_length / 4) + ray.texx];
			else if (ray.side == 1)
				data->color = data->texture[1].address[ray.texy * (data->texture[1].line_length / 4) + ray.texx];
			else if (ray.side == 2)
				data->color = data->texture[2].address[ray.texy * (data->texture[2].line_length / 4) + ray.texx];
			else if (ray.side == 3)
				data->color = data->texture[3].address[ray.texy * (data->texture[3].line_length / 4) + ray.texx];
			pixel_put_in_image(&data->img, x, y, data->color);
		}
		while (++y < WIN_HEIGHT)
			pixel_put_in_image(&data->img, x, y, encode_rgb(100, 100, 100));
	}
}

