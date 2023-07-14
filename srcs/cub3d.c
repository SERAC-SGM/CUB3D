/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:39:56 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/14 18:16:25 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_error(E_MLX, data);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		exit_error(E_MLX, data);
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

int	main(int argc, char **argv)
{
	t_data		data;
	t_map_data	map_data;
	t_player	player;

	data.mdata = &map_data;
	data.player = &player;
	if (check_arg(argc, argv, &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_map_data(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//print_map(data.mdata);
	//print_map_data(data.mdata);
	//print_player_data(data.player);
	//data.time = 0;
	//data.oldtime 1 = 0;
	init_window(&data);
	data.img.mlx_image = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img.address = mlx_get_data_addr(data.img.mlx_image,
			&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	if (!data.img.mlx_image || !data.img.address)
		exit_error(E_MLX, &data);
	raycasting(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_image, 0, 0);
	mlx_hook(data.win, KEY_PRESS, KeyPressMask, &handle_key_input, &data);
	mlx_hook(data.win, CLOSE_WINDOW, LeaveWindowMask, &quit_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

// int	render(t_data *data)
// {
// 	// if (!data->win)
// 	// 	exit_error(E_MLX, data);
// 	raycasting(data);
// 	return (0);
// }

//int	main(void)
//{
//	t_data	data;

//	data.player.posx = 22;
//	data.player.posy = 12;
//	data.player.dirx = -1;
//	data.player.diry = 0;
//	data.player.planex = 0;
//	data.player.planey = 0.66;
//	data.time = 0;
//	data.oldtime = 0;
//	init_window(&data);
//	data.img.mlx_image = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
//	data.img.address = mlx_get_data_addr(data.img.mlx_image, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
//	if (!data.img.mlx_image || !data.img.address)
//		exit_error(E_MLX, &data);
//	while (1)
//	{
//		//mlx_loop_hook(data.mlx, &render, &data);
//		//render(&data);
//		raycasting(&data);
//		mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_image, 0, 0);
//	}
//	return (0);
//}
