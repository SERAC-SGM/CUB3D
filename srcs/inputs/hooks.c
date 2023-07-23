/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:34:39 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/19 16:23:30 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//int	handle_mouse(int x, int y, t_data *data)
//{
//	(void)y;

//	printf("x is %d and prev y is %d\n", x, data->prev_mouse_w);
//	if (x > data->prev_mouse_w)
//	{
//		printf("x > prev x\n");
//		data->rotate_left = 1;
//	}
//	if (x < data->prev_mouse_w)
//	{
//		printf("x < prev x\n");
//		data->rotate_right = 1;
//	}
//	printf("moving mouse\n");
//	data->prev_mouse_w = x;
//	return (0);
//}

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
