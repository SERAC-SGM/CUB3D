/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:16:10 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst_arg	*ft_lstnew_arg(t_arg_spec *spec)
{
	t_lst_arg	*new_arg;

	if (!spec)
		return (NULL);
	new_arg = malloc(sizeof(t_lst_arg));
	if (!new_arg)
		return (NULL);
	new_arg->spec = spec;
	new_arg->next = NULL;
	return (new_arg);
}

t_lst_arg	*ft_lstlast_arg(t_lst_arg *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_arg(t_lst_arg **lst, t_lst_arg *new)
{
	t_lst_arg	*nlast;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	nlast = ft_lstlast_arg(*lst);
	nlast->next = new;
}

void	ft_lstdelone_arg(t_lst_arg *lst, void (*del)(t_arg_spec*))
{
	if (!lst)
		return ;
	(*del)(lst->spec);
	free(lst);
}

void	ft_lstclear_arg(t_lst_arg **lst)
{
	t_lst_arg	*nnext;
	void		(*del)(t_arg_spec*);

	del = &del_arg;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		nnext = (*lst)->next;
		ft_lstdelone_arg(*lst, del);
		*lst = nnext;
	}
}
