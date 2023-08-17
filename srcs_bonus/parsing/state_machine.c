/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:10:39 by mat               #+#    #+#             */
/*   Updated: 2023/08/16 10:18:04 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	one_state(t_machine *m, void (*f)(t_machine *m))
{
	const int	pos = m->mdata->map[m->i][m->j];

	if (pos == 9)
		m->state = NINE;
	else if (pos == 0)
		m->state = ZERO;
	f(m);
	return ;
}

void	zero_state(t_machine *m, void (*f)(t_machine *m))
{
	const int	pos = m->mdata->map[m->i][m->j];

	if (pos == 9)
	{
		m->valid = false;
		m->state = NINE;
	}
	else if (pos == 1)
		m->state = ONE;
	f(m);
}

void	nine_state(t_machine *m, void (*f)(t_machine *m))
{
	const int	pos = m->mdata->map[m->i][m->j];

	if (pos == 0)
	{
		m->valid = false;
		m->state = ZERO;
	}
	if (pos == 1)
		m->state = ONE;
	f(m);
}

void	first_pos_state(t_machine *m, void (*f)(t_machine *m))
{
	const int	pos = m->mdata->map[m->i][m->j];

	(void)f;
	if (pos == 1)
		m->state = ONE;
	else if (pos == 0)
		m->state = ZERO;
	else if (pos == 9)
		m->state = NINE;
}

void	init_machine(t_machine *machine)
{
	if (machine->mdata->map[0][0] == 0)
		machine->state = ZERO;
	else if (machine->mdata->map[0][0] == 1)
		machine->state = ONE;
	else if (machine->mdata->map[0][0] == 9)
		machine->state = NINE;
	machine->i = 0;
	machine->j = 0;
}
