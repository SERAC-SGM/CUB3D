/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:16:27 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/20 12:47:32 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_player_data(t_player *player)
{
	printf("posx is %f\n", player->posx);
	printf("posy is %f\n", player->posy);
	printf("dirx is %f\n", player->dirx);
	printf("diry is %f\n", player->diry);
	printf("planex is %f\n", player->planex);
	printf("planey is %f\n", player->planey);
}

// void	print_map_data(t_map_data *mdata)
// {
// 	printf("NO is %s\n", mdata->texture_path[0]);
// 	printf("SO is %s\n", mdata->texture_path[1]);
// 	printf("WE is %s\n", mdata->texture_path[2]);
// 	printf("EA is %s\n", mdata->texture_path[3]);
// 	printf("F is %d\n", mdata->color_f);
// 	printf("C is %d\n", mdata->color_c);
// }

void	print_strs(t_strlst *lst)
{
	while (lst)
	{
		printf("%s", lst->str);
		lst = lst->next;
	}
}

void	print_map(t_map_data *mdata)
{
	int	x;
	int	y;

	x = -1;
	while (++x < mdata->map_height)
	{
		y = -1;
		while (++y < mdata->map_width)
		{
			if (mdata->map[x][y] < 10)
				printf("%d", mdata->map[x][y]);
			else
				printf("%c", mdata->map[x][y]);
		}
		printf("\n");
	}
	printf("width = %d height = %d\n", mdata->map_width, mdata->map_height);
}
