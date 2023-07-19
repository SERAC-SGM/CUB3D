/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:47:03 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/19 14:06:02 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
