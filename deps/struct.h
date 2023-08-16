/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:55:49 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/16 11:27:42 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_states
{
	ZERO,
	ONE,
	NINE,
	FIRST_POS,
	END
}		t_states;

typedef struct s_coord
{
	int	x;
	int	y;
}			t_coord;

// typedef struct s_image
// {
// 	void	*mlx_image;
// 	char	*address;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_image;

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}			t_player;

typedef struct s_ray
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;

}			t_ray;

typedef struct s_strlst
{
	char			*str;
	struct s_strlst	*next;
}		t_strlst;

typedef struct s_map
{
	int			type;
	int			x;
	int			y;
	void		*img;
}				t_map;

typedef struct s_map_data
{
	int			**map;
	t_strlst	*map_strs;
	t_strlst	*top;
	int			map_fd;
	char		*texture[4];
	int			color_floor;
	int			color_ceiling;
	int			map_height;
	int			map_width;
}				t_map_data;

typedef struct s_image
{
	void	*mlx_image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_sprite_img
{
	void			*img;
	unsigned int	*address;
	int				index;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	//double			pos[100][2];

}					t_sprite_img;

typedef struct s_sprite
{
	double		pos[2];
	double		zbuffer[WIN_WIDTH];
	double		sprite_dist;
	double		xsprite;
	double		ysprite;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			vmove;
	int			drawstartspritey;
	int			drawendspritey;
	int			drawstartspritex;
	int			drawendspritex;
	int			sprite_width;
	int			stripe;
	int			spritetexx;
	int			spritetexy;
	int			d;
	int			color;
}				t_sprite;

typedef struct s_texture
{
	void			*img;
	unsigned int	*address;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_texture;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_image			img;
	t_player		*player;
	t_ray			ray;
	t_map_data		*mdata;
	t_texture		wall[4];
	t_texture		door;
	t_sprite_img	fire_img[4];
	t_sprite		fire[100];
	uint32_t		color;
	int				sprite_number;
	int				move_fwd;
	int				move_bckwd;
	int				move_left;
	int				move_right;
	int				rotate_left;
	int				rotate_right;
	int				prev_mouse_w;
	bool		mouse_hook;
	int				frame;
	int				index;
}					t_data;

typedef struct s_machine
{
	t_map_data	*mdata;
	t_states	state;
	t_states	prev_state;
	int			i;
	int			j;
	bool		valid;
}				t_machine;

#endif
