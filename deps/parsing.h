/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:05:11 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/26 15:19:32 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// Check_map_char
int			check_map_char(t_map_data *mdata);

// Check_map
int			check_map(t_data *data);
int			check_player(t_map_data *mdata);
void		update_coord_horizontal(t_machine *m);
void		update_coord_vertical(t_machine *m);

// Get_color
int			test_colors(t_map_data *mdata, char *line);

// Get player
int			get_player_data(t_data *data, char c, int i, int j);

// Get textures
int			get_texture_path(t_map_data *mdata);

// Init_sprite
void		init_walls_sprites(t_data *data);
int			get_sprite_pos(int x, int y, t_data *data);

// Mallocs
int			malloc_structs(t_data *data);

// Parsing utils
t_strlst	*ft_lstnew(void *content);
void		ft_lstadd_back(t_strlst **lst, t_strlst *new);
void		ft_lstclear(t_strlst **lst, void (*del)(void*));
char		*get_first_lst_ptr(t_map_data *mdata, char *line, int *tmp);

// Parsing
int			parsing(t_data *data);

// State machine
void		init_machine(t_machine *machine);
void		one_state(t_machine *m, void (*f)(t_machine *m));
void		zero_state(t_machine *m, void (*f)(t_machine *m));
void		nine_state(t_machine *m, void (*f)(t_machine *m));
void		first_pos_state(t_machine *m, void (*f)(t_machine *m));

#endif
