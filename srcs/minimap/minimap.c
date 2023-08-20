/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:49:07 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/20 12:01:15 by lletourn         ###   ########.fr       */
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

	pixel_x = (MINIMAP_W / 2) - (MINIMAP_W / MINIMAP_SIZE_X
			* MINIMAP_PLAYER_FACTOR);
	while (pixel_x < (MINIMAP_W / 2) + (MINIMAP_W / MINIMAP_SIZE_X
			* MINIMAP_PLAYER_FACTOR))
	{
		pixel_y = (MINIMAP_H / 2) - (MINIMAP_H / MINIMAP_SIZE_Y
				* MINIMAP_PLAYER_FACTOR);
		while (pixel_y < (MINIMAP_H / 2) + (MINIMAP_H / MINIMAP_SIZE_Y
				* MINIMAP_PLAYER_FACTOR))
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

// t_coord	get_map_coord(int pixel_x, int pixel_y, t_data *data)
// {
// 	t_coord	square;

// 	return (square);
// }

// static int	get_map_color(int square_x, int square_y, t_data *data)
// {
// 	// if (square_x < 0 || square_y < 0)
// 	// 	return (0);
// //printf("square x1 = %d\tsquare y1 = %d\n", square_x, square_y);
// 	square_x = (square_x + 0.0) / 100;
// 	square_y = (square_y + 0.0) / 100;
// 	//printf("square x2 = %d\tsquare y2 = %d\n", square_x, square_y);
// 	// printf("width = %d\n", data->mdata->map_width);
// 	// printf("squarex = %d\n", square_x);
// 	// printf("hieght = %d\n", data->mdata->map_height);
// 	// printf("squarey = %d\n", square_y);


// 	if (square_x < 0 || square_y < 0 || square_x > data->mdata->map_width - 1
// 		|| square_y > data->mdata->map_height - 1)
// 		return (0);
// 	else if (data->mdata->map[square_y][square_x] == 0
// 		|| data->mdata->map[square_y][square_x] == 9)
// 		return (0);
// 	else if (data->mdata->map[square_y][square_x] == 1)
// 		return (encode_rgb(255, 0, 255));
// 	else if (data->mdata->map[square_y][square_x] == 'D')
// 		return (encode_rgb(245, 241, 0));
// 	else if (data->mdata->map[square_y][square_x] == 'd')
// 		return (encode_rgb(150, 150, 0));
// 	else
// 	{
// 		//printf("%d\n", data->mdata->map[square_x][square_y]);
// 		return (encode_rgb(0, 255, 0));
// 	}
// }

static int	get_map_color2(int pixel_x, int pixel_y, t_data *data)
{
	int	square_size_x;
	int	square_size_y;
	int	square_pos_x;
	int	square_pos_y;
	int	square_x;
	int	square_y;

	square_size_x = MINIMAP_W / (X_SQUARE_NB * 2);
	printf("square size x = %d\n", square_size_x);
	printf("player x = %f\n", data->player->posx);
	square_size_y = MINIMAP_H / (Y_SQUARE_NB * 2);
	square_pos_x = (data->player->posx * 100) + (pixel_x / 2);
	square_pos_y = (data->player->posy * 100) + (pixel_y / 2);
	square_x = (((pixel_x - (MINIMAP_W / 2)) / square_size_x) + (data->player->posx * 100)) / 100;
	square_y = ((((MINIMAP_H / 2) - pixel_y) / square_size_y) + (data->player->posy * 100)) / 100;
	if (square_x < 0 || square_y < 0 || square_x > data->mdata->map_width - 1
		|| square_y > data->mdata->map_height - 1)
		return (encode_rgb(255, 255, 255));
	else if (data->mdata->map[square_y][square_x] == 0
		|| data->mdata->map[square_y][square_x] == 9)
		return (0);
	else if (data->mdata->map[square_y][square_x] == 1)
		return (encode_rgb(255, 0, 255));
	else if (data->mdata->map[square_y][square_x] == 'D')
		return (encode_rgb(245, 241, 0));
	else if (data->mdata->map[square_y][square_x] == 'd')
		return (encode_rgb(150, 150, 0));
	else
		return (encode_rgb(0, 255, 0));
}

void	minimap(t_data *data)
{
	int	pixel_x;
	int	pixel_y;
	int	square_color;

	pixel_y = -1;
	while (++pixel_y < MINIMAP_H + 1)
	{
		pixel_x = -1;
		while (++pixel_x < MINIMAP_W + 1)
		{
			square_color = get_map_color2(pixel_x, pixel_y, data);
			pixel_put_in_image(&data->img, pixel_x, pixel_y, square_color);
		}
	}
	draw_borders(data);
	draw_player(data);
}
