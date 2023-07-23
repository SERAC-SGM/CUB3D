/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:54:34 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/20 17:20:49 by mat              ###   ########.fr       */
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

void	put_texture_pixel(t_ray *ray, t_data *data, int x, int y)
{
	ray->texy = (int)ray->texpos & (data->texture[0].height - 1);
	ray->texpos += ray->step;
	if (ray->side == 0)
		data->color = data->texture[0].address[ray->texy
			* (data->texture[0].line_length / 4) + ray->texx];
	else if (ray->side == 1)
		data->color = data->texture[1].address[ray->texy
			* (data->texture[1].line_length / 4) + ray->texx];
	else if (ray->side == 2)
		data->color = data->texture[2].address[ray->texy
			* (data->texture[2].line_length / 4) + ray->texx];
	else if (ray->side == 3)
		data->color = data->texture[3].address[ray->texy
			* (data->texture[3].line_length / 4) + ray->texx];
	pixel_put_in_image(&data->img, x, y, data->color);
}
