/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:40:32 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/20 16:08:47 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_sprite_pos(int x, int y, t_data *data)
{
	if (data->fire_img->number == 99)
		exit_error(E_SPRITE, "Too many sprites", data);
	data->fire[data->fire_img->number].pos[0] = x + 0.5;
	data->fire[data->fire_img->number].pos[1] = y + 0.5;
	data->fire_img->number++;
	return (MAP_FLOOR);
}

// static void link_sprite(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < data->fire_img->number)
// 	{
// 		data->fire[i].pos[0] = 
// 		data->fire[i].address = data->fire_img[i].address;
// 		data->fire[i].width = data->fire_img[i].width;
// 		data->fire[i].height = data->fire_img[i].height;
// 	}
// }

void	init_walls_sprites(t_data *data)
{
	get_wall(data);
	get_door(data);
	get_sprite(data);
	// link_sprite(data);
	data->fire_img[0].number = 1; // TEMP
	data->fire[0].pos[0] = 1.5; // À parser correctement
	data->fire[0].pos[1] = 1.5; // À parser correctement
	data->frame = 0;
	data->index = 0;
}
