/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:44:16 by mat               #+#    #+#             */
/*   Updated: 2023/08/17 11:53:29 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color_composant(char *line, size_t *i)
{
	char	*nb_str;
	size_t	j;
	int		nb;

	nb_str = malloc(sizeof(char) * ft_strlen(line));
	j = 0;
	while (line[*i] && ft_isdigit(line[*i]) == 0)
		(*i)++;
	while (line[*i] && ft_isdigit(line[*i]) == 1)
	{
		nb_str[j] = line[*i];
		(*i)++;
		j++;
	}
	nb_str[j] = '\0';
	nb = ft_atoi(nb_str);
	free(nb_str);
	if (nb > 255)
		return (-1);
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
	if (r == -1 || g == -1 || b == -1 || line[i] != '\n')
		return (-1);
	return (get_rgb_colors(r, g, b));
}

void	test_colors(t_map_data *mdata, char *line, int *counter)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		(*counter)++;
		mdata->color_floor = get_color(line);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		(*counter)++;
		mdata->color_ceiling = get_color(line);
	}
}
