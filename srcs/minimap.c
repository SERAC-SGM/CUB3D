/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:43:34 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/20 14:24:28 by mat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_minimap_borders(t_data *data)
{
	int	x;
	int	y;
	int	color_border;

	color_border = encode_rgb(255, 255, 255);
	x = 0;
	y = 0;
	while (y < MINIMAP_W)
	{
		pixel_put_in_image(&data->img, y, 0, color_border);
		pixel_put_in_image(&data->img, y, 1, color_border);
		pixel_put_in_image(&data->img, y, MINIMAP_H - 1, color_border);
		pixel_put_in_image(&data->img, y, MINIMAP_H - 2, color_border);
		y++;
	}
	while (x < MINIMAP_H)
	{
		pixel_put_in_image(&data->img, 0, x, color_border);
		pixel_put_in_image(&data->img, 1, x, color_border);
		pixel_put_in_image(&data->img, MINIMAP_W - 1, x, color_border);
		pixel_put_in_image(&data->img, MINIMAP_W - 2, x, color_border);
		x++;
	}
}

static void	put_player_in_minimap(t_data *data)
{
	int	i;
	int	j;

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			pixel_put_in_image(&data->img, MINIMAP_W / 2 + i - 5,
				MINIMAP_H / 2 + j - 5, encode_rgb(255, 0, 0));
			j++;
		}
		i++;
	}
}

static int	get_minimap_color(t_data *data, t_coord top_corner, int i, int j)
{
	int	map_square_x;
	int	map_square_y;

	map_square_x = top_corner.x + i / 10;
	map_square_y = top_corner.y + j / 10;
	if (map_square_x < 0 || map_square_x > data->mdata->map_height - 1
		|| map_square_y < 0 || map_square_y > data->mdata->map_width - 1
		|| data->mdata->map[map_square_x][map_square_y] == 0)
		return (0);
	else if (data->mdata->map[map_square_x][map_square_y] == 'd'
			|| data->mdata->map[map_square_x][map_square_y] == 'D')
		return (encode_rgb(245, 241, 0));
	else
		return (encode_rgb(0, 0, 255));
}

void	fill_square(t_data *data, int color, int i, int j)
{
	int	k;
	int	l;

	k = 0;
	while (k < 10)
	{
		l = 0;
		while (l < 10)
		{
			pixel_put_in_image(&data->img, l + j, k + i, color);
			l++;
		}
		k++;
	}
}

void	minimap(t_data *data)
{
	t_coord			top_corner;
	int				i;
	int				j;
	int				color;

	i = 0;
	top_corner.x = data->player->posx - 6.0;
	top_corner.y = data->player->posy - 8.0;
	while (i < MINIMAP_H)
	{
		j = 0;
		while (j < MINIMAP_W)
		{
			color = get_minimap_color(data, top_corner, i, j);
			fill_square(data, color, i, j);
			j += 10;
		}
		i += 10;
	}
	put_minimap_borders(data);
	put_player_in_minimap(data);
}
