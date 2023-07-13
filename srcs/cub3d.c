/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:39:56 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/13 16:08:27 by mat              ###   ########.fr       */
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

void	raycasting(t_data	*data)
{
	int			x;
	t_player	player;
	t_ray		ray;

	player = data->player;
	ray = data->ray;
	x = -1;
	while (++x < WIN_WIDTH)
	{
		ray.camerax = 2 * x / WIN_WIDTH - 1;
		ray.raydirx = player.dirx + player.planex * ray.camerax;
		ray.raydiry = player.diry + player.planey * ray.camerax;
		ray.mapx = (int)player.posx;
		ray.mapy = (int)player.posy;
		ray.deltadistx = ft_abs(1 / ray.raydirx);
		ray.deltadisty = ft_abs(1 / ray.raydiry);
		ray.hit = 0;
		if (ray.raydirx < 0)
		{
			ray.stepx = -1;
			ray.sidedistx = (player.posx - ray.mapx) * ray.deltadistx;
		}
		else
		{
			ray.stepx = 1;
			ray.sidedistx = (ray.mapx + 1.0 - player.posx) * ray.deltadistx;
		}
		if (ray.raydiry < 0)
		{
			ray.stepy = -1;
			ray.sidedisty = (player.posy - ray.mapy) * ray.deltadisty;
		}
		else
		{
			ray.stepy = 1;
			ray.sidedisty = (ray.mapy + 1.0 - player.posy) * ray.deltadisty;
		}
		// DDA
		while (ray.hit == 0)
		{
			if (ray.sidedistx < ray.sidedisty)
			{
				ray.sidedistx += ray.deltadistx;
				ray.mapx += ray.stepx;
				ray.side = 0;
			}
			else
			{
				ray.sidedisty += ray.deltadisty;
				ray.mapy += ray.stepy;
				ray.side = 1;
			}
			if (worldMap[ray.mapx][ray.mapy] > 0)
				ray.hit = 1;
		}
		if (ray.side == 0)
			ray.perpwalldist = (ray.sidedistx - ray.deltadistx);
		else
			ray.perpwalldist = (ray.sidedisty - ray.deltadisty);
	}
}

int	done(void)
{
	return (0);
}

int	main(void)
{
	t_data	data;

	//get_map(&data);
	data.map = worldMap;
	data.player.posx = 22;
	data.player.posy = 12;
	data.player.dirx = -1;
	data.player.diry = 0;
	data.player.planex = 0;
	data.player.planey = 0.66;
	data.time = 0;
	data.oldtime = 0;
	init_window(&data);
	//mlx_loop(data.mlx);
	// while (!done())
	// {
	// }
	while (1)
		;
	return (0);
}
