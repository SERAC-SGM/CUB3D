/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:47:03 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/17 15:17:54 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_minimap_color(t_data *data, int x, int y)
{
	//(void)data;
	//(void)x;
	//(void)y;
	//const int	player_x = data->player->posx;
	//const int	player_y = data->player->posy;
	int			map_eqx;
	int			map_eqy;

	map_eqx = (int)((data->player->posx - WIN_HEIGHT) / SCALE / 2 + x);
	map_eqy = (int)((data->player->posy - WIN_WIDTH) / SCALE / 2 + y);
	printf("map eqx : %d\n", map_eqx);
	printf("map eqy : %d\n", map_eqy);
	//if (data->mdata->map[map_eqx][map_eqy] == 1)
	//	return (encode_rgb(255, 255, 255));
	//else
	//	return (0);
	return (0);
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
	(void)data;
	int	y;
	int	x;

	x = 0;
	while (x < MINIMAP_W)
	{
		y = 0;
		while (y < MINIMAP_H)
		{
			pixel_put_in_image(&data->img, x, y, get_minimap_color(data, x, y));
			y++;
		}
		x++;
	}
	put_minimap_borders(data);
}