/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:51:08 by mdorr             #+#    #+#             */
/*   Updated: 2023/07/11 15:48:15 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*trim_path(char *line)
{
	char	*path;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (line[i] != '.')
		i++;
	while (line[i])
	{
		i++;
		len++;
	}
	path = malloc(sizeof(char) * (len));
	i = i - len;
	len = 0;
	while (line[i] != '\n')
		path[len++] = line[i++];
	path[len] = '\0';
	return (path);
}

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

static int	get_color(char *line)
{
	int		nb1;
	int		nb2;
	int		nb3;
	char	*base;
	size_t	i;

	base = "0123456789ABCDEF";
	i = 0;
	nb1 = get_color_composant(line, &i);
	nb2 = get_color_composant(line, &i);
	nb3 = get_color_composant(line, &i);
	printf("nb1 : %d\nnb2 : %d\nnb3 : %d\n", nb1, nb2, nb3);

	return (1);
}

static void	store_texture(t_data *data, char *line, int *counter)
{
	if (ft_strncmp(line, "NO .", 4) == 0)
	{
		(*counter)++;
		data->path_texture_n = trim_path(line);
	}
	if (ft_strncmp(line, "SO .", 4) == 0)
	{
		(*counter)++;
		data->path_texture_s = trim_path(line);
	}
	if (ft_strncmp(line, "WE .", 4) == 0)
	{
		(*counter)++;
		data->path_texture_w = trim_path(line);
	}
	if (ft_strncmp(line, "EA .", 4) == 0)
	{
		(*counter)++;
		data->path_texture_e = trim_path(line);
	}
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		(counter)++;
		data->color_f = get_color(line);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		(counter)++;
		data->color_c = get_color(line);
	}
}

static void	get_texture_path(t_data *data)
{
	char	*line;
	int		counter;

	counter = 0;
	while (counter < 6)
	{
		line = get_next_line(data->map_fd);
		if (line == NULL)
			break ;
		while (line[0] == '\n')
		{
			free(line);
			line = get_next_line(data->map_fd);
		}
		store_texture(data, line, &counter);
		free(line);
	}
	return ;
}

//static int	get_map_size(int map_fd)
//{
//}

void	get_map_data(t_data *data)
{
	//int		**map;
	//size_t	size;

	get_texture_path(data);
	//size = get_map_size(data->map_fd);
}
