/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:28:52 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/17 11:35:53 by mdorr            ###   ########.fr       */
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
	data->move_fwd = 0;
	data->move_bckwd = 0;
	data->move_left = 0;
	data->move_right = 0;
	data->rotate_left = 0;
	data->rotate_right = 0;
	data->mdata = mdata;
	data->player = player;
}

void	init_images(t_data *data)
{
	data->img.mlx_image = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.address = mlx_get_data_addr(data->img.mlx_image,
			&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	if (!data->img.mlx_image || !data->img.address)
		exit_error(E_MLX, "image creation failed", data);
	data->minimap.mlx_image = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->minimap.address = mlx_get_data_addr(data->minimap.mlx_image,
			&data->minimap.bits_per_pixel, &data->minimap.line_length, &data->minimap.endian);
	if (!data->minimap.mlx_image || !data->minimap.address)
		exit_error(E_MLX, "minimap image creation failed", data);
}