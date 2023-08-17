/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:29:56 by lletourn          #+#    #+#             */
/*   Updated: 2023/07/15 20:30:01 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put_in_image(t_image *image, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = image->bits_per_pixel - 8;
	pixel = image->address + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (image->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (image->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}
