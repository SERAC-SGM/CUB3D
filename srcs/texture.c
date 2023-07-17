/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:54:34 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/17 11:46:24 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_wall(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		data->wall[i].img = mlx_xpm_file_to_image(data->mlx,
				data->mdata->texture_path[i], &data->wall[i].width,
				&data->wall[i].height);
		if (!data->wall[i].img)
			exit_error(E_TEXTURE, data->mdata->texture_path[i], data);
		data->wall[i].address = (unsigned int *)mlx_get_data_addr
			(data->wall[i].img, &data->wall[i].bits_per_pixel,
				&data->wall[i].line_length, &data->wall[i].endian);
	}
}

void	put_wall_pixel(t_ray *ray, t_data *data, int x, int y)
{
	ray->texy = (int)ray->texpos & (data->wall[0].height - 1);
	ray->texpos += ray->step;
	if (ray->side == 0)
		data->color = data->wall[0].address[ray->texy
			* (data->wall[0].line_length / 4) + ray->texx];
	else if (ray->side == 1)
		data->color = data->wall[1].address[ray->texy
			* (data->wall[1].line_length / 4) + ray->texx];
	else if (ray->side == 2)
		data->color = data->wall[2].address[ray->texy
			* (data->wall[2].line_length / 4) + ray->texx];
	else if (ray->side == 3)
		data->color = data->wall[3].address[ray->texy
			* (data->wall[3].line_length / 4) + ray->texx];
	pixel_put_in_image(&data->img, x, y, data->color);
}
