/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:47:03 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/18 12:24:21 by mat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player_in_minimap(t_data *data)
{
	int	i;
	int	j;

	i = -8;
	while (i < 8)
	{
		j = -8;
		while (j < 8)
		{
			pixel_put_in_image(&data->img, MINIMAP_H / 2 + i, MINIMAP_W / 2 + j, encode_rgb(255, 0, 0));
			j++;
		}
		i++;
	}
}

int	within_map_borders(t_coord *coord, t_data *data)
{
	int	x;
	int	y;

	x = data->player->posx + coord->x;
	y = data->player->posy + coord->y;

	if (x < 0 || x > data->mdata->map_width - 1
		|| y < 0 || y > data->mdata->map_height - 1)
		return (0);
	return (1);
}

int	get_minimap_color(t_data *data, int x, int y)
{
	const int	player_x = data->player->posx;
	const int	player_y = data->player->posy;
	t_coord		minimap_square;

	minimap_square.x = x * SCALE - 4;
	minimap_square.y = y * SCALE - 3;
	if (within_map_borders(&minimap_square, data) == 0
		|| data->mdata->map[player_y + minimap_square.y]
		[player_x + minimap_square.x]
		== 0)
		return (encode_rgb(0, 0, 0));
	else
		return (encode_rgb(255, 255, 255));
}

void	put_minimap_borders(t_data *data)
{
	int	x;
	int	y;
	int	color_border;

	color_border = encode_rgb(9, 135, 219);

	x = 0;
	y = 0;

	while (y < MINIMAP_H)
	{
		pixel_put_in_image(&data->img, 0, y, color_border);
		pixel_put_in_image(&data->img, 1, y, color_border);
		pixel_put_in_image(&data->img, MINIMAP_W - 1, y, color_border);
		pixel_put_in_image(&data->img, MINIMAP_W - 2, y, color_border);
		y++;
	}
	while (x < MINIMAP_W)
	{
		pixel_put_in_image(&data->img, x, 0, color_border);
		pixel_put_in_image(&data->img, x, 1, color_border);
		pixel_put_in_image(&data->img, x, MINIMAP_H - 1, color_border);
		pixel_put_in_image(&data->img, x, MINIMAP_H - 2, color_border);
		x++;
	}
}

void	minimap(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < MINIMAP_H)
	{
		x = 0;
		while (x < MINIMAP_W)
		{
			pixel_put_in_image(&data->img, x, y, get_minimap_color(data, x, y));
			x++;
		}
		y++;
	}
	put_minimap_borders(data);
	//put_player_in_minimap(data);
}
