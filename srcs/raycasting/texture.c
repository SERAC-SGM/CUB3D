/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:54:34 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/18 12:11:24 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_door(t_data *data)
{
	data->door.img = mlx_xpm_file_to_image(data->mlx,
			"./textures/lab/tile135.xpm",
			&data->door.width, &data->door.height);
	if (!data->door.img)
		exit_error(E_TEXTURE, "./textures/lab/tile135.xpm", data);
	data->door.address = (unsigned int *)mlx_get_data_addr
		(data->door.img, &data->door.bits_per_pixel,
			&data->door.line_length, &data->door.endian);
}

void	get_door_inside(t_data *data)
{
	data->door_inside.img = mlx_xpm_file_to_image(data->mlx,
			"./textures/lab/tile029.xpm",
			&data->door_inside.width, &data->door_inside.height);
	if (!data->door_inside.img)
		exit_error(E_TEXTURE, "./textures/lab/tile029.xpm", data);
	data->door_inside.address = (unsigned int *)mlx_get_data_addr
		(data->door_inside.img, &data->door_inside.bits_per_pixel,
			&data->door_inside.line_length, &data->door_inside.endian);
}

void	get_wall(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		data->wall[i].img = mlx_xpm_file_to_image(data->mlx,
				data->mdata->texture[i], &data->wall[i].width,
				&data->wall[i].height);
	}
	i = -1;
	while (++i < 4)
	{
		if (!data->wall[i].img)
			exit_error(E_TEXTURE, data->mdata->texture[i], data);
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
	else if (ray->side == 4 || ray->side == 5)
		data->color = data->door.address[ray->texy
			* (data->door.line_length / 4) + ray->texx];
	else if (ray->side == 6 || ray->side == 7)
		data->color = data->door_inside.address[ray->texy
			* (data->door_inside.line_length / 4) + ray->texx];
	pixel_put_in_image(&data->img, x, y, data->color);
}
