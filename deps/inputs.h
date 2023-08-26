/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:03:07 by lletourn          #+#    #+#             */
/*   Updated: 2023/08/26 15:16:47 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

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

// Door
void		change_door_state(t_data *data);

// Hooks
int			handle_key_press(int keycode, t_data *data);
int			handle_key_release(int keycode, t_data *data);
int			quit_window(t_data *data);
int			handle_mouse(int x, int y, t_data *data);

// Movement
void		move_player(t_data *data);
void		rotate_player_left(t_data *data);
#endif
