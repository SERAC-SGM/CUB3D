/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:44:16 by mat               #+#    #+#             */
/*   Updated: 2023/07/12 11:54:22 by mat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color_composant(char *line, size_t *i)
{
	char	*nb_str;
	size_t	j;
	int		nb;

	nb_str = malloc(sizeof(char) * 4);
	j = 0;
	while (ft_isdigit(line[*i]) == 0)
		(*i)++;
	while (ft_isdigit(line[*i]) == 1)
	{
		nb_str[j] = line[*i];
		(*i)++;
		j++;
	}
	nb_str[j] = '\0';
	nb = ft_atoi(nb_str);
	free(nb_str);
	return (nb);
}

int	get_rgb_colors(int r, int g, int b)
{
	int	color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return (color);
}

static int	get_color(char *line)
{
	size_t	i;
	int		r;
	int		g;
	int		b;

	i = 0;
	r = get_color_composant(line, &i);
	g = get_color_composant(line, &i);
	b = get_color_composant(line, &i);
	return (get_rgb_colors(r, g, b));
}

void	test_colors(t_map_data *mdata, char *line, int *counter)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		(*counter)++;
		mdata->color_f = get_color(line);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		(*counter)++;
		mdata->color_c = get_color(line);
	}
}
