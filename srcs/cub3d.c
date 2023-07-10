/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:39:56 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/10 15:14:15 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *error, t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	if (error)
		ft_putstr_fd(error, 2);
	exit(1);
}

void	init_window(t_data *data)
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

void	raycasting(t_data	*data)
{
	int		x;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;


	x = -1;
	while (++x < WIN_WIDTH)
	{
		cameraX = 2 * x / (double)WIN_WIDTH - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
	}
}

int	done(void)
{
	return (0);
}

// void	get_map(t_data *data)
// {

// }

int	main(void)
{
	t_data	data;

	get_map(&data);
	init_window(&data);
	// double posX = 22, posY = 12; //x and y start position
	// double dirX = -1, dirY = 0; //initial direction vector
	// double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
	// double time = 0; //time of current frame
	// double oldTime = 0; //time of previous frame
	//mlx_loop(data.mlx);
	// while (!done())
	// {

	// }
	while (1)
		;
	return (0);
}
