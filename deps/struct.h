/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:55:49 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/13 16:16:32 by mat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	int			map_fd;
	char		*path_texture_n;
	char		*path_texture_s;
	char		*path_texture_w;
	char		*path_texture_e;
	int			color_f;
	int			color_c;
	int			map_height;
	int			map_width;
}				t_map_data;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_player	player;
	t_ray		ray;
	t_map_data	mdata;
	double		time;
	double		oldtime;
	int			TEMPCOLOR;
}				t_data;

#endif
