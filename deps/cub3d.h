/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:52:53 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/16 14:04:32 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # define WIN_HEIGHT 480
// # define WIN_WIDTH 640

# define MINIMAP_H	120
# define MINIMAP_W	160

# define WIN_HEIGHT 600
# define WIN_WIDTH 800

// # define WIN_HEIGHT 768
// # define WIN_WIDTH 1024

# define MAP_HEIGHT	24
# define MAP_WIDTH	24

# define CLOSE_WINDOW 17
# define KEY_PRESS 2
# define KEY_RELEASE 3

# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESCAPE 65307
# define SPACE	32
# define W_KEY	119
# define S_KEY	115
# define A_KEY	97
# define D_KEY	100

# define MOVE_SPEED		0.06
# define ROTATE_SPEED	0.0375

# define MAP_VOID		9
# define MAP_FLOOR		0
# define MAP_WALL		1
# define MAP_DOOR_X		'd'
# define MAP_DOOR_Y		'D'
# define MAP_SPRITE		'S'
# define PLAYER_NORTH	2
# define PLAYER_SOUTH	3
# define PLAYER_EAST	4
# define PLAYER_WEST	5
# define OPEN_DOOR		'd'
# define CLOSED_DOOR	'D'

# define CLOSE_WINDOW 17
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_MOVE	6

# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESCAPE 65307
# define SPACE	32
# define W_KEY	119
# define S_KEY	115
# define A_KEY	97
# define D_KEY	100

# define SPRITE_1 "./textures/sprites/fire_1.xpm"
# define SPRITE_2 "./textures/sprites/fire_2.xpm"
# define SPRITE_3 "./textures/sprites/fire_3.xpm"
# define SPRITE_4 "./textures/sprites/fire_4.xpm"

# define E_MLX			"MiniLibX : "
# define E_TEXTURE		"Unable to load texture : "
# define E_COLOR		"Referenced colors in wrong format\nUse R, G, B Format\n"
# define E_PLAYER		"Wrong number of player in map, one player allowed\n"
# define E_UNCLOSED_MAP	"Wrong map format, maps need to be surrounded by walls\n"
# define E_SPRITE "Unable to load sprite : "

# define SPRITE_WIDTH 64
# define SPRITE_HEIGHT 64

# define UDIV 2
# define VDIV 2
# define VMOVE 125.0

# define FRAME_UPDATE	15
# define SPRITE_NB		4

# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "mlx.h"
# include "struct.h"

void		get_sprite(t_data *data);
void		display_fire_sprite(int x, t_data *data);
void		init_walls_sprites(t_data *data);
void		init_ray(int x, t_ray *ray, t_player *player);

///// PROTOTYPES /////

// Exit and free

void		exit_error(char *error, char *arg, t_data *data);
void		exit_clean(t_data *data);

// Init

void		init_window(t_data *data);
void		init_data(t_data *data, t_map_data *mdata, t_player *player);
void		init_image(t_data *data);

// Hooks

int			handle_key_press(int keycode, t_data *data);
int			handle_key_release(int keycode, t_data *data);
int			quit_window(t_data *data);
int			handle_mouse(int x, int y, t_data *data);

// Parsing

int			parsing(t_data *data);

// Mallocs

int			malloc_structs(t_data *data);

// Get_colors

void		test_colors(t_map_data *mdata, char *line, int *counter);

// Get textures

void		get_texture_path(t_map_data *mdata);

// Get player

int			get_player_and_door_data(t_data *data, char c, int i, int j);

// Parsing utils

t_strlst	*ft_lstnew(void *content);
void		ft_lstadd_back(t_strlst **lst, t_strlst *new);
void		ft_lstclear(t_strlst **lst, void (*del)(void*));

// Check map

int			check_map(t_data *data);
int			check_player(t_map_data *mdata);
void		update_coord_horizontal(t_machine *m);
void		update_coord_vertical(t_machine *m);

// State machine

void		init_machine(t_machine *machine);
void		one_state(t_machine *m, void (*f)(t_machine *m));
void		zero_state(t_machine *m, void (*f)(t_machine *m));
void		nine_state(t_machine *m, void (*f)(t_machine *m));
void		first_pos_state(t_machine *m, void (*f)(t_machine *m));

// Raycasting

void		raycasting(t_data	*data);

// Movement

void		move_player(t_data *data);
void		rotate_player_left(t_data *data);

// Colors
int			encode_rgb(__uint8_t red, __uint8_t green, __uint8_t blue);

// Texture

void		get_wall(t_data *data);
void		put_wall_pixel(t_ray *ray, t_data *data, int x, int y);

// Window

void		pixel_put_in_image(t_image *image, int x, int y, int color);

// Minimap

void		minimap(t_data *data);

// Minimap utils

int			get_int_rouded(float nbr);

// Door

void		change_door_state(t_data *data);

// Debug

void		print_player_data(t_player *player);
//void		print_map_data(t_map_data *mdata);
void		print_map(t_map_data *mdata);
void		print_strs(t_strlst *lst);

//void		show_all_sprites(int x, t_data *data);
void		get_door(t_data *data);
int			get_sprite_pos(int x, int y, t_data *data);
void		get_door_inside(t_data *data);


#endif
