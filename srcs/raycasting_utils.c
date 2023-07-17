/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:48:53 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/17 16:48:57 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(int x, t_ray *ray, t_player *player)
{
	ray->camerax = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydirx = player->dirx + player->planex * ray->camerax;
	ray->raydiry = player->diry + player->planey * ray->camerax;
	ray->mapx = player->posx;
	ray->mapy = player->posy;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	ray->hit = 0;
}
