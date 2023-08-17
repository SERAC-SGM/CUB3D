/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:17:49 by mat               #+#    #+#             */
/*   Updated: 2023/08/17 15:57:59 by lletourn         ###   ########.fr       */
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
	int			i;
	t_strlst	*top;

	top = mdata->map_strs;
	if (mdata->map_strs == NULL)
		return (print_error(E_NOMAP));
	while (mdata->map_strs)
	{
		i = 0;
		while (mdata->map_strs->str[i])
		{
			if (ft_strchr("01+NSEWDd \n", mdata->map_strs->str[i]) == NULL)
				return (print_error(E_INVALID_CHAR));
			i++;
		}
		mdata->map_strs = mdata->map_strs->next;
	}
	mdata->map_strs = top;
	return (EXIT_SUCCESS);
}
