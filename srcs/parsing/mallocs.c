/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:42:53 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/17 12:07:52 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	free_prev_allocs(t_data *data, int i)
{
	while (i >= 0)
		free(data->mdata->map[i--]);
	free(data->mdata->map);
	return (EXIT_FAILURE);
}

int	malloc_structs(t_data *data)
{
	int		i;

	i = 0;
	data->mdata->map = malloc(sizeof(int *) * data->mdata->map_height);
	if (data->mdata->map == NULL)
		return (EXIT_FAILURE);
	while (i < data->mdata->map_height)
	{
		data->mdata->map[i] = malloc(sizeof(int) * data->mdata->map_width);
		if (data->mdata->map[i] == NULL)
			return (free_prev_allocs(data, i));
		i++;
	}
	return (EXIT_SUCCESS);
}
