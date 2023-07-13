/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:39:56 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/13 15:26:44 by mat              ###   ########.fr       */
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

void	print_map(t_map_data *mdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mdata->map_height)
	{
		j = 0;
		while (j < mdata->map_width)
		{
			printf("%d", mdata->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_map_data	map_data;

	data.mdata = &map_data;
	if (check_arg(argc, argv, &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	get_map_data(data.mdata);
	print_map(data.mdata);
	init_window(&data);
	mlx_hook(data.win, KEY_PRESS, KeyPressMask, &handle_key_input, &data);
	mlx_hook(data.win, CLOSE_WINDOW, LeaveWindowMask, &quit_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

// void	fill(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < WIN_WIDTH)
// 	{
// 		y = 0;
// 		while (y < WIN_HEIGHT)
// 		{
// 			mlx_pixel_put(data->mlx, data->win, x, y, 0x00FF0000);
// 			y++;
// 		}
// 		x++;
// 	}
// }

//void	raycasting(t_data	*data)
//{
//	int		x;
//	double	cameraX;
//	double	rayDirX;
//	double	rayDirY;


//	x = -1;
//	while (++x < WIN_WIDTH)
//	{
//		cameraX = 2 * x / (double)WIN_WIDTH - 1;
//		double rayDirX = dirX + planeX * cameraX;
//		double rayDirY = dirY + planeY * cameraX;
//	}
//}

//int	done(void)
//{
//	return (0);
//}
