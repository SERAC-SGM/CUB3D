/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:02:17 by maaliber          #+#    #+#             */
/*   Updated: 2023/05/22 12:11:09 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	wd_count(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == 0))
			cnt++;
		i++;
	}
	return (cnt);
}

size_t	wd_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	idx_l;
	size_t	len;
	size_t	i;

	tab = malloc(sizeof(char *) * (wd_count(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	i = 0;
	idx_l = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = wd_len(s + i, c);
			tab[idx_l] = ft_substr(s + i, 0, len);
			if (!tab[idx_l++])
				return (free_tab(tab), NULL);
			i += len;
		}
		else
			i++;
	}
	return (tab[idx_l] = NULL, tab);
}
