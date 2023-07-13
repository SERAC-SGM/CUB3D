/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:39:56 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/13 17:24:34 by mat              ###   ########.fr       */
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


int	encode_rgb(__uint8_t red, __uint8_t green, __uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}


void	pixel_put_in_image(t_image *image, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = image->bits_per_pixel - 8;
	pixel = image->address + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (image->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (image->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}
int	get_color(t_data *data)
{
	if (data->mdata->map[data->ray.mapx][data->ray.mapy] == 1)
		return (encode_rgb(255, 0, 0));
	if (data->mdata->map[data->ray.mapx][data->ray.mapy] == 2)
		return (encode_rgb(0, 255, 0));
	if (data->mdata->map[data->ray.mapx][data->ray.mapy] == 3)
		return (encode_rgb(0, 0, 255));
	if (data->mdata->map[data->ray.mapx][data->ray.mapy] == 4)
		return (encode_rgb(255, 255, 255));
	else
		return (encode_rgb(127, 127, 127));
}

void	draw_line(int x, t_data *data)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < data->ray.drawstart)
			pixel_put_in_image(&data->img, x, y, encode_rgb(0, 0, 0));
		else if (y >= data->ray.drawstart && y <= data->ray.drawend)
			pixel_put_in_image(&data->img, x, y, data->TEMPCOLOR);
		else if (y > data->ray.drawend)
			pixel_put_in_image(&data->img, x, y, encode_rgb(50, 50, 50));
	}
}

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
		ray.camerax = 2 * x / (double)WIN_WIDTH - 1;
		ray.raydirx = player.dirx + player.planex * ray.camerax;
		ray.raydiry = player.diry + player.planey * ray.camerax;
		ray.mapx = player.posx;
		ray.mapy = player.posy;
		ray.deltadistx = fabs(1 / ray.raydirx);
		ray.deltadisty = fabs(1 / ray.raydiry);
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
		printf("hola\n");
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
			if (data->mdata->map[ray.mapx][ray.mapy] > 0)
				ray.hit = 1;
		}
		printf("hola\n");
		if (ray.side == 0)
			ray.perpwalldist = (ray.sidedistx - ray.deltadistx);
		else
			ray.perpwalldist = (ray.sidedisty - ray.deltadisty);
		ray.lineheight = WIN_HEIGHT / ray.perpwalldist;
		ray.drawstart = -ray.lineheight / 2 + WIN_HEIGHT / 2;
		if (ray.drawstart < 0)
			ray.drawstart = 0;
		ray.drawend = ray.lineheight / 2 + WIN_HEIGHT / 2;
		if (ray.drawend >= WIN_HEIGHT)
			ray.drawend = WIN_HEIGHT - 1;
		data->ray = ray;
		data->TEMPCOLOR = get_color(data);
		if (ray.side)
			data->TEMPCOLOR = data->TEMPCOLOR / 2;
		draw_line(x, data);
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
	data.player.posx = 22;
	data.player.posy = 12;
	data.player.dirx = -1;
	data.player.diry = 0;
	data.player.planex = 0;
	data.player.planey = 0.66;
	data.time = 0;
	data.oldtime = 0;
	init_window(&data);
	data.img.mlx_image = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img.address = mlx_get_data_addr(data.img.mlx_image,
			&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	if (!data.img.mlx_image || !data.img.address)
		exit_error(E_MLX, &data);
	printf("raycasting\n");
	raycasting(&data);
	printf("raycasting done\n");
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
