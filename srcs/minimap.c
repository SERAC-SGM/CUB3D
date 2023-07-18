/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:47:03 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/18 16:31:05 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_minimap_borders(t_data *data)
{
	int	x;
	int	y;
	int	color_border;

	color_border = encode_rgb(9, 135, 219);

	x = 0;
	y = 0;

	while (y < MINIMAP_W)
	{
		pixel_put_in_image(&data->img, 0, y, color_border);
		pixel_put_in_image(&data->img, 1, y, color_border);
		pixel_put_in_image(&data->img, MINIMAP_H - 1, y, color_border);
		pixel_put_in_image(&data->img, MINIMAP_H - 2, y, color_border);
		y++;
	}
	while (x < MINIMAP_H)
	{
		pixel_put_in_image(&data->img, x, 0, color_border);
		pixel_put_in_image(&data->img, x, 1, color_border);
		pixel_put_in_image(&data->img, x, MINIMAP_W - 1, color_border);
		pixel_put_in_image(&data->img, x, MINIMAP_W - 2, color_border);
		x++;
	}
}

void	put_player_in_minimap(t_data *data)
{
	int	i;
	int	j;

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
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

	x = data->player->posx + coord->h;
	y = data->player->posy + coord->w;

	if (x < 0 || x > data->mdata->map_height - 1
		|| y < 0 || y > data->mdata->map_width  - 1)
		return (0);
	return (1);
}

int	get_minimap_color(t_data *data, int x, int y)
{
	const int	player_h = data->player->posx;
	const int	player_w = data->player->posy;
	t_coord		minimap_square;

	minimap_square.h = x * SCALE - 3;
	minimap_square.w = y * SCALE - 4;
	//printf("minimap x is %d, minimap y is %d\n", minimap_square.x, minimap_square.y);
	if (within_map_borders(&minimap_square, data) == 0
		|| data->mdata->map[player_h + minimap_square.h]
		[player_w + minimap_square.w]
		== 0)
		return (encode_rgb(0, 0, 0));
	else
		return (encode_rgb(255, 255, 255));
}

//int	get_minimap_color(t_data *data, int x, int y)
//{
//	const int	player_h = data->player->posx;
//	const int	player_w = data->player->posy;
//	t_coord		minimap_square;

//	minimap_square.h = x / 20 - 1;
//	minimap_square.w = y / 20 - 1;
//	printf("x is %d, y is %d\n", x, y);
//	printf("minimap x is %d, minimap y is %d\n", minimap_square.h, minimap_square.w);
//	printf("player_h is %d, player_w is %d\n", player_h, player_w);
//	if (within_map_borders(&minimap_square, data) ||
//		data->mdata->map[player_h + minimap_square.h - 3]
//		[player_w + minimap_square.w - 4]
//		== 0)
//		return (encode_rgb(0, 0, 0));
//	else
//		return (encode_rgb(255, 255, 255));


//}

void	minimap(t_data *data)
{
	(void)data;
	int	y;
	int	x;

	x = 0;
	while (x < MINIMAP_H)
	{
		y = 0;
		while (y < MINIMAP_W)
		{
			pixel_put_in_image(&data->img, x, y, get_minimap_color(data, x, y));
			y++;
		}
		x++;
	}
	put_minimap_borders(data);
	put_player_in_minimap(data);
}
