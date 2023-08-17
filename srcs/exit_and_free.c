/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:50:07 by mat               #+#    #+#             */
/*   Updated: 2023/08/17 10:44:22 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map_data *mdata)
{
	int	i;

	i = 0;
	while (i < mdata->map_height)
	{
		free(mdata->map[i]);
		i++;
	}
	free(mdata->map);
}

void	exit_parsing(t_data *data)
{
	int	i;

	i = -1;
	free_map(data->mdata);
	while (++i < 4)
		free(data->mdata->texture[i]);
	free(data->player);
	exit(1);
}

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(data->mlx, data->wall[i].img);
		mlx_destroy_image(data->mlx, data->fire_img[i].img);
	}
	mlx_destroy_image(data->mlx, data->door.img);
	mlx_destroy_image(data->mlx, data->door_inside.img);
	mlx_destroy_image(data->mlx, data->img.mlx_image);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	data->win = NULL;
	free_map(data->mdata);
	i = -1;
	while (++i < 4)
		free(data->mdata->texture[i]);
	free(data->player);
}

void	exit_error(char *error, char *arg, t_data *data)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\n", 2);
	free_data(data);
	exit(1);
}

void	exit_clean(t_data *data)
{
	free_data(data);
	exit(0);
}
