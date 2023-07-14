/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:16:27 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/14 14:19:42 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_data(t_map_data *mdata)
{
	printf("NO is %s\n", mdata->path_texture_n);
	printf("SO is %s\n", mdata->path_texture_s);
	printf("WE is %s\n", mdata->path_texture_w);
	printf("EA is %s\n", mdata->path_texture_e);
	printf("F is %d\n", mdata->color_f);
	printf("C is %d\n", mdata->color_c);
}
void	print_map(t_map_data *mdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mdata->map_height)
	{
		j = 0;
		while(j < mdata->map_width)
			printf("%d", mdata->map[i][j++]);
		printf("\n");
		i++;
	}
}