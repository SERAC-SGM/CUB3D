/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:43:34 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/19 11:06:09 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_out_of_bounds(t_data *data, int x, int y)
{
	return (x < 0 || x > data->mdata->map_height - 1
		|| y < 0 || y > data->mdata->map_width  - 1);
}

int	get_minimap_color(t_data *data, double x, double y)
{
	if (is_out_of_bounds(data, (int)x, (int)y) == 1)
		return (0);
	else
		return (data->mdata->map[(int)x][(int)y]);

}
void	minimap(t_data *data)
{
	const double	top_corner_x = data->player->posx - 4;
	const double	top_corner_y = data->player->posy - 3;
	int				i;
	int				j;

	i = 0;
	printf("hola\n");
	while (i < MINIMAP_H)
	{
		j = 0;
		while (j < MINIMAP_W)
		{
			pixel_put_in_image(data->img.mlx_image, j, i,
				get_minimap_color(data, top_corner_x + i, top_corner_y + j));
			j++;
		}
		i++;
	}
	//printf("player pos x is %f\n", data->player->posx);
	//printf("player pos y is %f\n", data->player->posy);
	//printf("top corner x is %f\n", top_corner_x);
	//printf("top corner y is %f\n", top_corner_y);
}