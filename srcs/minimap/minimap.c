/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:49:07 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/18 17:04:28 by lletourn         ###   ########.fr       */
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
	int	pixel_x;
	int	pixel_y;

	pixel_x = (MINIMAP_W / 2) - (MINIMAP_W / MINIMAP_SIZE_X * 0.5);
	while (pixel_x < (MINIMAP_W / 2) + (MINIMAP_W / MINIMAP_SIZE_X * 0.5))
	{
		pixel_y = (MINIMAP_H / 2) - (MINIMAP_H / MINIMAP_SIZE_Y * 0.5);
		while (pixel_y < (MINIMAP_H / 2) + (MINIMAP_H / MINIMAP_SIZE_Y * 0.5))
		{
			pixel_put_in_image(&data->img, pixel_x,
				pixel_y, encode_rgb(255, 0, 0));
			pixel_y++;
		}
		pixel_x++;
	}
}

// static int	get_minimap_color(t_data *data, t_coord top_corner, int pixel_x, int pixel_y)
// {
// 	double	map_square_x;
// 	double	map_square_y;

// 	map_square_x = top_corner.x + (double)(pixel_x / MINIMAP_SIZE_X); // a modif ?
// 	map_square_y = top_corner.y + (double)(pixel_y / MINIMAP_SIZE_Y); //same
// 	if (map_square_y < 0 || map_square_y > data->mdata->map_height - 1
// 		|| map_square_x < 0 || map_square_x > data->mdata->map_width - 1
// 		|| data->mdata->map[(int)map_square_x][(int)map_square_y] == 1)
// 		return (encode_rgb(0, 0, 255));
// 	else if (data->mdata->map[(int)map_square_x][(int)map_square_y] == 'D')
// 		return (encode_rgb(245, 241, 0));
// 	else if (data->mdata->map[(int)map_square_x][(int)map_square_y] == 'd')
// 		return (encode_rgb(150, 150, 0));
// 	else
// 		return (encode_rgb(0, 0, 0));
// }

// void	fill_square(t_data *data, int color, int pixel_x, int pixel_y)
// {
// 	int	k;
// 	int	l;

// 	k = 0;
// 	while (k < 10)
// 	{
// 		l = 0;
// 		while (l < 10)
// 		{
// 			pixel_put_in_image(&data->img, l + pixel_y, k + pixel_x, color);
// 			l++;
// 		}
// 		k++;
// 	}
// }

// void	minimap(t_data *data)
// {
// 	t_coord			top_corner;
// 	int				pixel_x;
// 	int				pixel_y;
// 	int				color;

// 	pixel_y = -1;
// 	top_corner.x = (int)data->player->posx - (MINIMAP_SIZE_X / 2);
// 	top_corner.y = (int)data->player->posy - (MINIMAP_SIZE_Y / 2);
// 	while (++pixel_y < MINIMAP_H)
// 	{
// 		pixel_x = -1;
// 		while (++pixel_x < MINIMAP_W)
// 		{
// 			color = get_minimap_color(data, top_corner, pixel_x, pixel_y);
// 			fill_square(data, color, pixel_x, pixel_y);
// 		}
// 	}
// 	put_minimap_borders(data);
// 	put_player_in_minimap(data);
// }

void	minimap(t_data *data)
{
	int	pixel_x;
	int	pixel_y;
	int	x_square_size;
	int	y_square_size;
	int	first_x_square_pos;
	int	first_y_square_pos;

	x_square_size = MINIMAP_W / MINIMAP_SIZE_X;
	y_square_size = MINIMAP_H / MINIMAP_SIZE_Y;
	first_x_square_pos = 

	//x_map_start = 
	pixel_y = -1;
	while (++pixel_y < MINIMAP_H)
	{
		pixel_x = -1;
		while (++pixel_x < MINIMAP_W)
		{

		}
	}
	put_minimap_borders(data);
	put_player_in_minimap(data);
}
