/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:26:28 by mat               #+#    #+#             */
/*   Updated: 2023/08/09 16:34:17 by mat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static int	print_error(char *error)
//{
//	ft_putstr_fd("Error\n", 2);
//	ft_putstr_fd(error, 2);
//	return (EXIT_FAILURE);
//}

//static int	check_player(t_map_data *mdata)
//{
//	int		player_counter;
//	int		i;
//	char	c;

//	player_counter = 0;
//	mdata->map_strs = mdata->top;
//	while (mdata->map_strs)
//	{
//		i = 0;
//		while (mdata->map_strs->str[i])
//		{
//			c = mdata->map_strs->str[i];
//			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
//				player_counter++;
//			i++;
//		}
//		mdata->map_strs = mdata->map_strs->next;
//	}
//	if (player_counter != 1)
//	{
//		ft_putstr_fd("Error\n", 2);
//		ft_putstr_fd(E_PLAYER, 2);
//		return (EXIT_FAILURE);
//	}
//	return (EXIT_SUCCESS);
//}

//int	check_first_and_last_row(t_map_data *mdata)
//{
//	int	j1;
//	int	i1;
//	int	i2;
//	int	j2;

//	j1 = 0;
//	i1 = 0;
//	while (j1 < mdata->map_width)
//	{
//		if (mdata->map[0][j1] < 1 || mdata->map[mdata->map_height - 1][j1] < 1)
//			return (print_error(E_UNCLOSED_MAP));
//		j1++;
//	}
//	i2 = 0;
//	j2 = 0;
//	while (i1 < mdata->map_height)
//	{
//		if (mdata->map[i2][0] < 1 || mdata->map[i2][mdata->map_width - 1] < 1)
//			return (print_error(E_UNCLOSED_MAP));
//		i2++;
//	}
//	return (EXIT_SUCCESS);
//}

//int	check_rows(t_map_data *mdata)
//{
//	int i;
//	int	j;

//	i = 0;
//	j = 0;
//	while (i < mdata->map_width)
//	{
//		if (i == 0 || i == mdata->map_height - 1)
//	}	
//}

//int	check_map(t_data *data)
//{
//	if (check_first_and_last_row(data->mdata) == EXIT_FAILURE
//		|| check_player(data->mdata) == EXIT_FAILURE)
//		return (EXIT_FAILURE);
//	return (EXIT_SUCCESS);
//}

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
	}
	(m->i)++;
}

int	check_map(t_data *data)
{
	t_machine	machine;
	static void	(*s_map_func[])(t_machine *, void (*f)(t_machine *m)) = {
		one_state,
		zero_state,
		nine_state
	};

	machine.mdata = data->mdata;
	machine.valid = true;
	printf("height is %d width is %d\n", data->mdata->map_height, data->mdata->map_width);
	init_machine(&machine);
	while (machine.state != END && machine.valid != false)
		s_map_func[machine.state](&machine, update_coord_horizontal);
	printf("machine after horizontal verif %d\n", machine.valid);
	printf("i is %d and j is %d\n", machine.i, machine.j);
	printf("machine state is %d\n", machine.state);
	init_machine(&machine);
	while (machine.state != END && machine.valid != false)
		s_map_func[machine.state](&machine, update_coord_vertical);
	printf("machine after vertical verif %d\n", machine.valid);
	if (machine.valid == true)
		return (0);
	return (1);
}
