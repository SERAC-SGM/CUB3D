/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:49:07 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/21 11:27:33 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_borders(t_data *data)
{
	int	x;
	int	y;
	int	color_border;

	color_border = encode_rgb(255, 255, 255);
	x = 0;
	y = 0;
	while (y < MINIMAP_W + 3)
	{
		pixel_put_in_image(&data->img, y, 0, color_border);
		pixel_put_in_image(&data->img, y, 1, color_border);
		pixel_put_in_image(&data->img, y, MINIMAP_H + 1, color_border);
		pixel_put_in_image(&data->img, y, MINIMAP_H + 2, color_border);
		y++;
	}
	while (x < MINIMAP_H + 3)
	{
		pixel_put_in_image(&data->img, 0, x, color_border);
		pixel_put_in_image(&data->img, 1, x, color_border);
		pixel_put_in_image(&data->img, MINIMAP_W + 1, x, color_border);
		pixel_put_in_image(&data->img, MINIMAP_W + 2, x, color_border);
		x++;
	}
}

static void	draw_player(t_data *data)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = (MINIMAP_W / 2) - (MINIMAP_W / MINIMAP_SIZE_X * MINIMAP_PLAYER_FACTOR);
	while (pixel_x < (MINIMAP_W / 2) + (MINIMAP_W / MINIMAP_SIZE_X * MINIMAP_PLAYER_FACTOR))
	{
		pixel_y = (MINIMAP_H / 2) - (MINIMAP_H / MINIMAP_SIZE_Y * MINIMAP_PLAYER_FACTOR);
		while (pixel_y < (MINIMAP_H / 2) + (MINIMAP_H / MINIMAP_SIZE_Y * MINIMAP_PLAYER_FACTOR))
		{
			pixel_put_in_image(&data->img, pixel_x,
				pixel_y, encode_rgb(255, 0, 0));
			pixel_y++;
		}
		pixel_x++;
	}
}

static int	get_map_color2(int pixel_x, int pixel_y, t_data *data)
{
	int	square_size_x;
	int	square_size_y;
	int	square_x;
	int	square_y;

	square_size_x = MINIMAP_W / (X_SQUARE_NB * 2);
	square_size_y = MINIMAP_H / (Y_SQUARE_NB * 2);
	square_y = pixel_x / square_size_x + data->player->posx - X_SQUARE_NB;
	square_x = pixel_y / square_size_y + data->player->posy - Y_SQUARE_NB;
	if (square_x < 0 || square_y < 0 || square_x > data->mdata->map_width - 1 || square_y > data->mdata->map_height - 1)
		return (encode_rgb(0, 0, 255));
	else if (data->mdata->map[square_y][square_x] == 0 || data->mdata->map[square_y][square_x] == 9)
		return (0);
	else if (data->mdata->map[square_y][square_x] == 1)
		return (encode_rgb(0, 0, 255));
	else if (data->mdata->map[square_y][square_x] == 'D')
		return (encode_rgb(245, 241, 0));
	else if (data->mdata->map[square_y][square_x] == 'd')
		return (encode_rgb(150, 150, 0));
	else
		return (encode_rgb(0, 255, 0));
}

void	minimap(t_data *data)
{
	int	square_size_x;
	int	square_size_y;
	int	pixel_x;
	int	pixel_y;
	int	square_color;

	square_size_x = MINIMAP_W / (X_SQUARE_NB * 2);
	square_size_y = MINIMAP_H / (Y_SQUARE_NB * 2);
	pixel_y = -1;
	while (++pixel_y < MINIMAP_H + 1)
	{
		pixel_x = -1;
		while (++pixel_x < MINIMAP_W + 1)
		{
			square_color = get_map_color2(pixel_y + 5 * square_size_y / 2, pixel_x - square_size_x * 3 / 2, data);
			pixel_put_in_image(&data->img, pixel_x, pixel_y, square_color);
		}
	}
	draw_borders(data);
	draw_player(data);
}
