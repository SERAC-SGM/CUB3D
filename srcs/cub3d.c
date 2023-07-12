/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:39:56 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/11 15:01:55 by lletourn         ###   ########.fr       */
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

int	encode_rgb(__uint8_t red, __uint8_t green, __uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	get_color(t_data *data)
{
	if (worldMap[data->ray.mapx][data->ray.mapy] == 1)
		return (encode_rgb(255, 0, 0));
	if (worldMap[data->ray.mapx][data->ray.mapy] == 2)
		return (encode_rgb(0, 255, 0));
	if (worldMap[data->ray.mapx][data->ray.mapy] == 3)
		return (encode_rgb(0, 0, 255));
	if (worldMap[data->ray.mapx][data->ray.mapy] == 4)
		return (encode_rgb(255, 255, 255));
	else
		return (encode_rgb(127, 127, 127));
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

void	draw_line(int x, t_data *data)
{
	int	y;

	y = -1;
	// printf("start %d\n", data->ray.drawstart);
	// printf("end %d\n", data->ray.drawend);
	while (++y < WIN_HEIGHT)
	{
		if (y < data->ray.drawstart)
			pixel_put_in_image(&data->img, x, y, encode_rgb(0, 0, 0));
		else if (y >= data->ray.drawstart && y <= data->ray.drawend)
			pixel_put_in_image(&data->img, x, y, data->TEMPCOLOR);
		else if (y > data->ray.drawend)
			pixel_put_in_image(&data->img, x, y, encode_rgb(0, 0, 0));
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
		ray.camerax = 2 * x / WIN_WIDTH - 1;
		ray.raydirx = player.dirx + player.planex * ray.camerax;
		ray.raydiry = player.diry + player.planey * ray.camerax;
		ray.mapx = player.posx;
		ray.mapy = player.posy;
		if (ray.raydirx == 0)
			ray.deltadistx = 1e30;
		else
		ray.deltadistx = ft_abs(1 / ray.raydirx);
		if (ray.raydiry == 0)
			ray.deltadisty = 1e30;
		else
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
		ray.lineheight = WIN_HEIGHT / ray.perpwalldist;
		ray.drawstart = -ray.lineheight / 2 + WIN_HEIGHT / 2;
		if (ray.drawstart < 0)
			ray.drawstart = 0;
		ray.drawend = ray.lineheight / 2 + WIN_HEIGHT / 2;
		if (ray.drawend >= WIN_HEIGHT)
			ray.drawend = WIN_HEIGHT - 1;
		//data->TEMPCOLOR = get_color(data);
		data->TEMPCOLOR = encode_rgb(0, 255, 0);
		// if (ray.side)
		// 	data->TEMPCOLOR = data->TEMPCOLOR / 2;
		draw_line(x, data);
	}
}

// int	render(t_data *data)
// {
// 	// if (!data->win)
// 	// 	exit_error(E_MLX, data);
// 	raycasting(data);
// 	return (0);
// }

int	main(void)
{
	t_data	data;

	//get_map(&data);
	//data.map = worldMap;
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
	data.img.address = mlx_get_data_addr(data.img.mlx_image, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	if (!data.img.mlx_image || !data.img.address)
		exit_error(E_MLX, &data);
	while (1)
	{
		//mlx_loop_hook(data.mlx, &render, &data);
		//render(&data);
		raycasting(&data);
		mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_image, 0, 0);
	}
	return (0);
}
