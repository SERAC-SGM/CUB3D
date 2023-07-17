/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:40:32 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/17 17:04:34 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_walls_sprites(t_data *data)
{
	get_wall(data);
	get_sprite(data);
	data->fire[0].pos[0][0] = 100.0; // À parser correctement
	data->fire[0].pos[0][1] = 100.0; // À parser correctement
	data->frame = 0;
	data->index = 0;
}
