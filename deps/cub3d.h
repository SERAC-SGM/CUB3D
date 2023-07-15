/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:52:53 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/15 17:03:15 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_HEIGHT 480
# define WIN_WIDTH 640
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define E_MLX "MiniLibX error\n"

# define MAP_HEIGHT	24
# define MAP_WIDTH	24

# define CLOSE_WINDOW 17
# define KEY_PRESS 2

# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESCAPE 65307

# define MAP_VOID		9
# define MAP_FLOOR		0
# define MAP_WALL		1
# define PLAYER_NORTH	2
# define PLAYER_SOUTH	3
# define PLAYER_EAST	4
# define PLAYER_WEST	5

# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include <X11/X.h>
# include <X11/keysym.h>

///// PROTOTYPES /////

// Cub3D

void		exit_error(char *error, t_data *data);

// Exit and free

void		exit_error(char *error, t_data *data);

// Hooks

int			handle_key_input(int keycode, t_data *data);
int			quit_window(t_data *data);

// Parsing

int			get_map_data(t_data *data);

// Mallocs

int			malloc_structs(t_data *data);

// Get_colors

void		test_colors(t_map_data *mdata, char *line, int *counter);

// Get textures

void		get_texture_path(t_map_data *mdata);

// Get player

int			get_player_data(t_data *data, char c, int i, int j);

// Parsing utils

t_strlst	*ft_lstnew(void *content);
void		ft_lstadd_back(t_strlst **lst, t_strlst *new);
void		ft_lstclear(t_strlst **lst, void (*del)(void*));

// Raycasting
void		raycasting(t_data	*data);

// Debug

void		print_player_data(t_player *player);
void		print_map_data(t_map_data *mdata);
void		print_map(t_map_data *mdata);

# define TEX_WIDTH 64

//int worldMap[MAP_WIDTH][MAP_HEIGHT]=
//{
//  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};

#endif
