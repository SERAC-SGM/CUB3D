/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:26:28 by mat               #+#    #+#             */
/*   Updated: 2023/07/20 18:01:22 by mat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	print_error(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	return (EXIT_FAILURE);
}

static int	check_player(t_map_data *mdata)
{
	int		player_counter;
	int		i;
	char	c;

	player_counter = 0;
	mdata->map_strs = mdata->top;
	while (mdata->map_strs)
	{
		i = 0;
		while (mdata->map_strs->str[i])
		{
			c = mdata->map_strs->str[i];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				player_counter++;
			i++;
		}
		mdata->map_strs = mdata->map_strs->next;
	}
	if (player_counter != 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(E_PLAYER, 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_first_and_last_row(t_map_data *mdata)
{
	int	j;
	int	i;

	j = 0;
	while (j < mdata->map_width)
	{
		if (mdata->map[0][j] < 1 || mdata->map[mdata->map_height - 1][j] < 1)
			return (print_error(E_UNCLOSED_MAP));
		j++;
	}
	i = 0;
	while (i < mdata->map_height)
	{
		if (mdata->map[i][0] < 1 || mdata->map[i][mdata->map_width - 1] < 1)
			return (print_error(E_UNCLOSED_MAP));
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_map(t_data *data)
{
	if (check_first_and_last_row(data->mdata) == EXIT_FAILURE
		|| check_player(data->mdata) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
