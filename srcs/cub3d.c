/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:39:56 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/10 17:02:07 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *error, t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	data->win = NULL;
	if (error)
		ft_putstr_fd(error, 2);
	exit(1);
}

static void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_error(E_MLX, data);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		exit_error(E_MLX, data);
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

// void	get_map(t_data *data)
// {

// }

int	main(void)
{
	t_data	data;

	//get_map(&data);
	init_window(&data);
	mlx_hook(data.win, KEY_PRESS, KeyPressMask, &handle_key_input, &data);
	mlx_hook(data.win, CLOSE_WINDOW, LeaveWindowMask, &quit_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
