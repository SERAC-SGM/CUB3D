/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:55:49 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/12 18:38:43 by mat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	t_map_data	*mdata;
}				t_data;

#endif
