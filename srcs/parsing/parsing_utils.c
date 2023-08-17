/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:17:49 by mat               #+#    #+#             */
/*   Updated: 2023/08/17 14:08:41 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_strlst	*ft_lstnew(void *content)
{
	t_strlst	*new;

	new = (t_strlst *)malloc(sizeof(t_strlst));
	if (new != NULL)
	{
		new->str = content;
		new->next = NULL;
	}
	return (new);
}

void	ft_lstadd_back(t_strlst **lst, t_strlst *new)
{
	t_strlst	*tmp_lst;

	if (lst != NULL && new != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp_lst = *lst;
			while (tmp_lst->next != NULL)
				tmp_lst = tmp_lst->next;
			tmp_lst->next = new;
		}
	}
}

static void	ft_lstdelone(t_strlst *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		if (del != NULL)
			del(lst->str);
		free(lst);
	}
}

void	ft_lstclear(t_strlst **lst, void (*del)(void*))
{
	t_strlst	*tmp_lst;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			tmp_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp_lst;
		}
	}
}

char	*get_first_lst_ptr(t_map_data *mdata, char *line, int *tmp)
{
	ft_lstadd_back(&mdata->map_strs, ft_lstnew(ft_strdup(line)));
	mdata->map_height++;
	*tmp = ft_strlen(line);
	if (*tmp - 1 > mdata->map_width)
		mdata->map_width = *tmp - 1;
	free(line);
	line = get_next_line(mdata->map_fd);
	mdata->top = mdata->map_strs;
	return (line);
}