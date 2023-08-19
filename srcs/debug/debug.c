/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:16:27 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/19 16:31:08 by lletourn         ###   ########.fr       */
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
	int	i;
	int	j;

	i = -1;
	while (++i < mdata->map_height)
	{
		j = -1;
		while (++j < mdata->map_width)
		{
			if (mdata->map[i][j] < 10)
				printf("%d", mdata->map[i][j]);
			else
				printf("%c", mdata->map[i][j]);
		}
		printf("\n");
	}
}
