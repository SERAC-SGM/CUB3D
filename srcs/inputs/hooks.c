/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:34:39 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/17 11:47:09 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_mouse(int x, int y, t_data *data)
{
	(void)y;
	data->mouse_hook = true;
	if (x > data->prev_mouse_w)
		data->rotate_right = 1;
	if (x < data->prev_mouse_w)
		data->rotate_left = 1;
	data->prev_mouse_w = x;
	//if (x >= WIN_WIDTH - 50 || x <= 50 || y >= WIN_HEIGHT - 50 || y <= 50)
	//	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

int	handle_key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		exit_clean(data);
	if (keycode == LEFT_ARROW)
		data->rotate_left = 1;
	if (keycode == RIGHT_ARROW)
		data->rotate_right = 1;
	if (keycode == W_KEY)
		data->move_fwd = 1;
	if (keycode == S_KEY)
		data->move_bckwd = 1;
	if (keycode == A_KEY)
		data->move_left = 1;
	if (keycode == D_KEY)
		data->move_right = 1;
	if (keycode == SPACE)
		change_door_state(data);
	return (0);
}

int	handle_key_release(int keycode, t_data *data)
{
	if (keycode == LEFT_ARROW)
		data->rotate_left = 0;
	if (keycode == RIGHT_ARROW)
		data->rotate_right = 0;
	if (keycode == W_KEY)
		data->move_fwd = 0;
	if (keycode == S_KEY)
		data->move_bckwd = 0;
	if (keycode == A_KEY)
		data->move_left = 0;
	if (keycode == D_KEY)
		data->move_right = 0;
	return (0);
}

int	quit_window(t_data *data)
{
	exit_clean(data);
	return (0);
}
