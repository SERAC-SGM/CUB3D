/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:52:53 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/26 15:28:38 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # define WIN_WIDTH 800
// # define WIN_HEIGHT 600

// # define WIN_WIDTH 640
// # define WIN_HEIGHT 480

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define MINIMAP_W	160
# define MINIMAP_H	120

//number of squares displayed in the minimap
# define MINIMAP_SIZE_X	16
# define MINIMAP_SIZE_Y	12

//player size in the minimap
# define MINIMAP_PLAYER_FACTOR 0.25

# define MOVE_SPEED		0.05
# define ROTATE_SPEED	0.03

# define MAP_VOID		9
# define MAP_FLOOR		0
# define MAP_WALL		1
# define MAP_SPRITE		'+'
# define OPEN_DOOR		'd'
# define CLOSED_DOOR	'D'

# define SPRITE_WIDTH 64
# define SPRITE_HEIGHT 64

# define UDIV 2
# define VDIV 2
# define VMOVE 200.0

# define FRAME_UPDATE	15
# define SPRITE_NB		4

# define E_MLX			"MiniLibX : "
# define E_TEXTURE		"Unable to load texture : "
# define E_COLOR		"Referenced colors in wrong format\nUse R, G, B Format\n"
# define E_PLAYER		"Incorrect number of player\n"
# define E_UNCLOSED_MAP	"Wrong map format\n"
# define E_SPRITE		"Unable to load sprite : "
# define E_INVALID_CHAR	"Invalid map\n"
# define E_NOMAP		"Empty map\n"
# define E_MISSING_TXT	"A texture or color is missing\n"

# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include "inputs.h"
# include "parsing.h"
# include "raycasting.h"

# include <X11/Xlib.h>
# include <X11/Xutil.h>

// Exit_and_free
void		exit_error(char *error, char *arg, t_data *data);
void		exit_clean(t_data *data);
void		exit_parsing(t_data *data);

// Init
void		init_window(t_data *data);
void		init_data(t_data *data, t_map_data *mdata, t_player *player);
void		init_image(t_data *data);
void		init_malloc(t_data *data);

// Minimap
void		minimap(t_data *data);

// Print_error
int			print_error(char *message);

// Window
void		pixel_put_in_image(t_image *image, int x, int y, int color);

#endif
