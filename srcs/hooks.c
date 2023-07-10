/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:34:39 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/10 15:35:00 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key_input(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		exit_error("Destroyed window\n", data);
	return (0);
}

int	quit_window(t_data *data)
{
	exit_error("Destroyed window\n", data);
	return (0);
}
