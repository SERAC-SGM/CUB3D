/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:40:32 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/16 14:04:07 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_sprite_pos(int x, int y, t_data *data)
{
	if (data->sprite_number == 99)
		exit_error(E_SPRITE, "Too many sprites", data);
	data->fire[data->sprite_number].pos[0] = x + 0.5;
	data->fire[data->sprite_number].pos[1] = y + 0.5;
	data->sprite_number++;
	return (MAP_FLOOR);
}

void	init_walls_sprites(t_data *data)
{
	get_wall(data);
	get_door(data);
	get_door_inside(data);
	get_sprite(data);
	data->frame = 0;
	data->index = 0;
}
