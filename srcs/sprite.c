/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:32:40 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/17 16:46:38 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_sprites(t_data *data)
{
	data->fire[0].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprites/fire_1.xpm", &data->fire[0].width,
			&data->fire[0].height);
	data->fire[1].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprites/fire_2.xpm", &data->fire[1].width,
			&data->fire[1].height);
	data->fire[2].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprites/fire_3.xpm", &data->fire[2].width,
			&data->fire[2].height);
	data->fire[3].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/sprites/fire_4.xpm", &data->fire[3].width,
			&data->fire[3].height);
	if (!data->fire[0].img)
		exit_error(E_TEXTURE, "./textures/sprites/fire_1.xpm", data);
	if (!data->fire[1].img)
		exit_error(E_TEXTURE, "./textures/sprites/fire_2.xpm", data);
	if (!data->fire[2].img)
		exit_error(E_TEXTURE, "./textures/sprites/fire_3.xpm", data);
	if (!data->fire[3].img)
		exit_error(E_TEXTURE, "./textures/sprites/fire_4.xpm", data);
}

void	get_sprite(t_data *data)
{
	load_sprites(data);
	data->fire[0].address = (unsigned int *)mlx_get_data_addr
		(data->fire[0].img, &data->fire[0].bits_per_pixel,
			&data->fire[0].line_length, &data->fire[0].endian);
	data->fire[1].address = (unsigned int *)mlx_get_data_addr
		(data->fire[1].img, &data->fire[1].bits_per_pixel,
			&data->fire[1].line_length, &data->fire[1].endian);
	data->fire[2].address = (unsigned int *)mlx_get_data_addr
		(data->fire[2].img, &data->fire[2].bits_per_pixel,
			&data->fire[2].line_length, &data->fire[2].endian);
	data->fire[3].address = (unsigned int *)mlx_get_data_addr
		(data->fire[3].img, &data->fire[3].bits_per_pixel,
			&data->fire[3].line_length, &data->fire[3].endian);
}

static void	get_sprite_distance_1(int x, t_sprite *sprite, t_player *player,
	t_ray *ray)
{
	sprite->zbuffer[x] = ray->perpwalldist;
	sprite->sprite_dist = ((player->posx - sprite->pos[0][0])
			* (player->posx - sprite->pos[0][0]) + (player->posy
				- sprite->pos[0][1]) * (player->posy - sprite->pos[0][1]));
	sprite->xsprite = sprite->pos[0][0] - player->posx;
	sprite->ysprite = sprite->pos[0][1] - player->posy;
	sprite->invdet = 1.0 / (player->planex * player->diry - player->dirx
			* player->planey);
	sprite->transformx = sprite->invdet * (player->diry * sprite->xsprite
			- player->dirx * sprite->ysprite);
	sprite->transformy = sprite->invdet * (-player->planey * sprite->xsprite
			+ player->planex * sprite->ysprite);
	sprite->spritescreenx = (int)((WIN_WIDTH / 2)
			* (1 + sprite->transformx / sprite->transformy));
	sprite->vmove = (int)(VMOVE / sprite->transformy);
	sprite->spriteheight = abs((int)(WIN_HEIGHT / (sprite->transformy))) / VDIV;
	sprite->drawstartspritey = -sprite->spriteheight / 2 + WIN_HEIGHT / 2
		+ sprite->vmove;
	if (sprite->drawstartspritey < 0)
		sprite->drawstartspritey = 0;
	sprite->drawendspritey = sprite->spriteheight / 2 + WIN_HEIGHT / 2
		+ sprite->vmove;
	if (sprite->drawendspritey >= WIN_HEIGHT)
		sprite->drawendspritey = WIN_HEIGHT - 1;
}

static void	draw_sprite( int y, t_sprite *sprite, t_data *data)
{
	while (++sprite->stripe < sprite->drawendspritex)
	{
		sprite->spritetexx = (int)(256 * (sprite->stripe
					- (-sprite->sprite_width / 2 + sprite->spritescreenx))
				* SPRITE_WIDTH / sprite->sprite_width) / 256;
		if (sprite->transformy > 0 && sprite->transformy
			< sprite->zbuffer[sprite->stripe])
		{
			y = sprite->drawstartspritey - 1;
			while (++y < sprite->drawendspritey)
			{
				sprite->d = (y - sprite->vmove) * 256 - WIN_HEIGHT * 128
					+ sprite->spriteheight * 128;
				sprite->spritetexy = ((sprite->d * SPRITE_HEIGHT)
						/ sprite->spriteheight) / 256;
				sprite->color
					= data->fire[data->index].address[sprite->spritetexy
					* (data->fire[data->index].line_length / 4)
					+ sprite->spritetexx];
				if ((sprite->color & 0x00FFFFFF) != 0)
					pixel_put_in_image(&data->img, sprite->stripe, y,
						sprite->color);
			}
		}
	}
}

void	display_fire_sprite(int x, t_data *data)
{
	t_sprite	sprite;
	t_player	player;
	t_ray		ray;

	player = *data->player;
	ray = data->ray;
	sprite = data->fire[0];
	get_sprite_distance_1(x, &sprite, &player, &ray);
	sprite.sprite_width = abs((int)(WIN_HEIGHT / (sprite.transformy))) / UDIV;
	sprite.drawstartspritex = -sprite.sprite_width / 2 + sprite.spritescreenx;
	if (sprite.drawstartspritex < 0)
		sprite.drawstartspritex = 0;
	sprite.drawendspritex = sprite.sprite_width / 2 + sprite.spritescreenx;
	if (sprite.drawendspritex >= WIN_WIDTH)
		sprite.drawendspritex = WIN_WIDTH - 1;
	sprite.stripe = sprite.drawstartspritex - 1;
	draw_sprite(0, &sprite, data);
}
