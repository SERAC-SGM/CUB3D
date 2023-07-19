/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:55:49 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/19 15:44:17 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_coord
{
	int	h;
	int	w;
}			t_coord;

typedef struct s_image
{
	void	*mlx_image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

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
	double	zbuffer[WIN_WIDTH];
	double	sprite_dist;
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
	char		*texture_path[4];
	int			color_f;
	int			color_c;
	int			map_height;
	int			map_width;
}				t_map_data;

typedef struct s_texture
{
	void			*img;
	unsigned int	*address;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}			t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_player	*player;
	t_ray		ray;
	t_map_data	*mdata;
	t_texture	texture[4];
	uint32_t	color;
	int			move_fwd;
	int			move_bckwd;
	int			move_left;
	int			move_right;
	int			rotate_left;
	int			rotate_right;
	int			prev_mouse_w;
}				t_data;

#endif
