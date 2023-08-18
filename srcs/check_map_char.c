/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:07:53 by mdorr             #+#    #+#             */
/*   Updated: 2023/08/17 16:24:44 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_char(t_map_data *mdata)
{
	int			i;
	t_strlst	*top;

	top = mdata->map_strs;
	if (mdata->map_strs == NULL
		|| mdata->map_width == 0 || mdata->map_height == 0)
		return (print_error(E_NOMAP));
	while (mdata->map_strs)
	{
		i = 0;
		while (mdata->map_strs->str[i])
		{
			if (ft_strchr("01NSEW \n", mdata->map_strs->str[i]) == NULL)
				return (print_error(E_INVALID_CHAR));
			i++;
		}
		mdata->map_strs = mdata->map_strs->next;
	}
	mdata->map_strs = top;
	return (EXIT_SUCCESS);
}
