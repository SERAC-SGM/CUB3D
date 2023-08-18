/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:28:52 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/18 12:45:06 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_error(E_MLX, "init failed", data);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		exit_error(E_MLX, "window creation failed", data);
}

void	init_data(t_data *data, t_map_data *mdata, t_player *player)
{
	int	i;

	i = 0;
	while (i < 4)
		mdata->texture[i++] = NULL;
	data->move_fwd = 0;
	data->move_bckwd = 0;
	data->move_left = 0;
	data->move_right = 0;
	data->rotate_left = 0;
	data->rotate_right = 0;
	data->mdata = mdata;
	mdata->map_strs = NULL;
	mdata->color_ceiling = -1;
	mdata->color_floor = -1;
	data->player = player;
	data->mdata->map = NULL;
	data->mouse_hook = false;
	data->sprite_number = 0;
}

void	init_image(t_data *data)
{
	data->img.mlx_image = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.mlx_image)
		exit_error(E_MLX, "image creation failed", data);
	data->img.address = mlx_get_data_addr(data->img.mlx_image,
			&data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (!data->img.address)
		exit_error(E_MLX, "image creation failed", data);
}

void	init_malloc(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		data->wall[i].img = NULL;
		data->fire_img[i].img = NULL;
	}
	data->door.img = NULL;
	data->door_inside.img = NULL;
	data->img.mlx_image = NULL;
	data->win = NULL;
	data->mlx = NULL;
}
