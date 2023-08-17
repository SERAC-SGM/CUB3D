/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:26:28 by mat               #+#    #+#             */
/*   Updated: 2023/08/17 15:05:01 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player(t_map_data *mdata)
{
	int		player_counter;
	int		i;
	char	c;

	player_counter = 0;
	mdata->map_strs = mdata->top;
	while (mdata->map_strs)
	{
		i = -1;
		while (mdata->map_strs->str[++i])
		{
			c = mdata->map_strs->str[i];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				player_counter++;
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < mdata->map_width)
	{
		if (mdata->map[0][j] < 1 || mdata->map[mdata->map_height - 1][j] < 1)
		{
			return (EXIT_FAILURE);
		}
		j++;
	}
	while (i < mdata->map_height)
	{
		if (mdata->map[i][0] < 1 || mdata->map[i][mdata->map_width - 1] < 1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	update_coord_horizontal(t_machine *m)
{
	if (m->i + 1 >= m->mdata->map_height
		&& m->j + 1 >= m->mdata->map_width)
	{
		m->state = END;
		return ;
	}
	else if (m->j + 1 >= m->mdata->map_width)
	{
		(m->i)++;
		(m->j) = 0;
		m->state = FIRST_POS;
	}
	(m->j)++;
}

void	update_coord_vertical(t_machine *m)
{
	if (m->i + 1 >= m->mdata->map_height
		&& m->j + 1 >= m->mdata->map_width)
	{
		m->state = END;
		return ;
	}
	else if (m->i + 1 >= m->mdata->map_height)
	{
		(m->j)++;
		(m->i) = 0;
		m->state = FIRST_POS;
	}
	(m->i)++;
}

int	check_map(t_data *data)
{
	t_machine	machine;
	static void	(*s_map_func[])(t_machine *, void (*f)(t_machine *m)) = {
		zero_state,
		one_state,
		nine_state,
		first_pos_state
	};

	machine.mdata = data->mdata;
	machine.valid = true;
	printf("blata\n");
	if (check_first_and_last_row(data->mdata) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	printf("blat after firts and lasyt\n");
	init_machine(&machine);
	while (machine.state != END && machine.valid != false)
		s_map_func[machine.state](&machine, update_coord_horizontal);
	init_machine(&machine);
	while (machine.state != END && machine.valid != false)
		s_map_func[machine.state](&machine, update_coord_vertical);
	if (machine.valid == true)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
