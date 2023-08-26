/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:03:42 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/26 15:20:50 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define SPRITE_1 "./textures/sprites/fire_1.xpm"
# define SPRITE_2 "./textures/sprites/fire_2.xpm"
# define SPRITE_3 "./textures/sprites/fire_3.xpm"
# define SPRITE_4 "./textures/sprites/fire_4.xpm"

// Raycasting_utils
void		check_door_hit(t_ray *ray);
void		check_door_inside_hit(t_ray *ray, t_data *data);
void		init_ray(int x, t_ray *ray, t_player *player);

// Raycasting
void		raycasting(t_data	*data);

// Colors
int			encode_rgb(__uint8_t red, __uint8_t green, __uint8_t blue);

// Sprite
void		get_sprite(t_data *data);
void		display_fire_sprite(int x, t_data *data);

// Texture
void		get_door(t_data *data);
void		get_door_inside(t_data *data);
void		get_wall(t_data *data);
void		put_wall_pixel(t_ray *ray, t_data *data, int x, int y);

#endif
