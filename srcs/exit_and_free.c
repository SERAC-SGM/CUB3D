/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:50:07 by mat               #+#    #+#             */
/*   Updated: 2023/07/15 17:27:37 by mdorr            ###   ########.fr       */
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

void	exit_error(char *error, t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	data->win = NULL;
	free_map(data->mdata);
	free(data->mdata->path_texture_n);
	free(data->mdata->path_texture_s);
	free(data->mdata->path_texture_e);
	free(data->mdata->path_texture_w);
	free(data->player);
	if (error)
		ft_putstr_fd(error, 2);
	exit(1);
}
