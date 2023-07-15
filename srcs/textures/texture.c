/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:54:34 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/15 19:20:32 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		data->texture[i].img = mlx_xpm_file_to_image(data->mlx,
				data->mdata->texture_path[i], &data->texture[i].width,
				&data->texture[i].height);
		if (!data->texture[i].img)
			exit_error(E_TEXTURE, data->mdata->texture_path[i], data);
		data->texture[i].address = (unsigned int *)mlx_get_data_addr
			(data->texture[i].img, &data->texture[i].bits_per_pixel,
				&data->texture[i].line_length, &data->texture[i].endian);
	}
}
