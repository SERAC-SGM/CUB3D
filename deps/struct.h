/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:55:49 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/11 15:23:50 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	int		type;
	int		x;
	int		y;
	void	*img;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		**map;
	int		map_fd;
	char	*path_texture_n;
	char	*path_texture_s;
	char	*path_texture_w;
	char	*path_texture_e;
	int		color_f;
	int		color_c;
}				t_data;

#endif
