/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:39:56 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/15 20:40:39 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_error(E_MLX, "init failed", data);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		exit_error(E_MLX, "window creation failed", data);
}

int	render(t_data *data)
{
	raycasting(data);
	move_player(data);
	rotate_player_left(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_image, 0, 0);
	return (0);
}

int	check_arg(int argc, char **argv, t_data *data)
{
	int	map_fd;

	if (argc != 2)
	{
		ft_putstr_fd("You need to put the map path in argument\n", 2);
		return (EXIT_FAILURE);
	}
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
	{
		ft_putstr_fd("Map path invalid\n", 2);
		return (EXIT_FAILURE);
	}
	else
		data->mdata->map_fd = map_fd;
	return (EXIT_SUCCESS);
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

int	main(int argc, char **argv)
{
	t_data		data;
	t_map_data	mdata;
	t_player	player;

	init_data(&data, &mdata, &player);
	if (check_arg(argc, argv, &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_map_data(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_window(&data);
	get_texture(&data);
	data.img.mlx_image = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img.address = mlx_get_data_addr(data.img.mlx_image,
			&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	if (!data.img.mlx_image || !data.img.address)
		exit_error(E_MLX, "image creation failed", &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_image, 0, 0);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KEY_PRESS, KeyPressMask, &handle_key_press, &data);
	mlx_hook(data.win, KEY_RELEASE, KeyReleaseMask, &handle_key_release, &data);
	mlx_hook(data.win, CLOSE_WINDOW, LeaveWindowMask, &quit_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
