/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:50:07 by mat               #+#    #+#             */
/*   Updated: 2023/07/17 11:01:33 by mdorr            ###   ########.fr       */
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

void	exit_error(char *error, char *arg, t_data *data)
{
	int	i;

	i = -1;
	write(2, "Error\n", 6);
	if (error)
		ft_putstr_fd(error, 2);
	if (arg)
		ft_putstr_fd(arg, 2);
	if (error)
		ft_putstr_fd("\n", 2);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	data->win = NULL;
	free_map(data->mdata);
	while (++i < 4)
		free(data->mdata->texture_path[i]);
	free(data->player);
	exit(1);
}
