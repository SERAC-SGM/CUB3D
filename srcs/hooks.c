/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:34:39 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/14 18:46:56 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	return ;
}

void	move_player(int keycode, t_data *data)
{
	if (keycode == )
}

int	handle_key_input(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		exit_error("Destroyed window\n", data);
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		rotate_player(keycode, data);
	else if (keycode == W_KEY || keycode == S_KEY
		|| keycode == A_KEY || keycode == D_KEY)
		move_player(keycode, data);
	return (0);
}

int	quit_window(t_data *data)
{
	exit_error("Destroyed window\n", data);
	return (0);
}
