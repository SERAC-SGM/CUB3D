/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:43:34 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/19 14:21:30 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_minimap_borders(t_data *data)
{
	int	x;
	int	y;
	int	color_border;

	color_border = encode_rgb(9, 135, 219);

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
			pixel_put_in_image(&data->img, MINIMAP_W / 2 + i, MINIMAP_H / 2 + j, encode_rgb(255, 0, 0));
			j++;
		}
		i++;
	}
}

static int	is_out_of_bounds(t_data *data, int x, int y)
{
	return (x < 0 || x > data->mdata->map_height - 1
		|| y < 0 || y > data->mdata->map_width  - 1);
}

static int	get_minimap_color(t_data *data, double x, double y, int i, int j)
{
	int	map_square_x;
	int	map_square_y;

	map_square_x = x + (i + 5)/10;
	map_square_y = y + (j + 5)/10;

	if (is_out_of_bounds(data, map_square_x, map_square_y) == 1 || data->mdata->map[map_square_x][map_square_y] == 0)
		return (0);
	else
	{
		return (encode_rgb(0, 0, 255));
	}

}
void	minimap(t_data *data)
{
	const double	top_corner_x = data->player->posx - 6.0;
	const double	top_corner_y = data->player->posy - 8.0;
	int				i;
	int				j;

	i = 0;
	while (i < MINIMAP_H)
	{
		j = 0;
		while (j < MINIMAP_W)
		{
			pixel_put_in_image(&data->img, j, i,
				get_minimap_color(data, top_corner_x, top_corner_y, i, j));
			j++;
		}
		i++;
	}
	put_minimap_borders(data);
	put_player_in_minimap(data);
}