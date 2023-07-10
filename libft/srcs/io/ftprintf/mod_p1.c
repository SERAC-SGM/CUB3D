/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_p1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:27:56 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ctype_mod(t_output *output, t_arg_spec *spec)
{
	char	*mod_c;
	ssize_t	add_size;

	add_size = spec->param.width - output->size;
	if (add_size > 0)
	{
		mod_c = ft_setalloc(sizeof(char) * add_size + 1, ' ', 0);
		if (!mod_c)
			return ;
		if (spec->param.left)
			mod_c[0] = *(output->to_print);
		else
			mod_c[add_size] = *(output->to_print);
		free(output->to_print);
		output->to_print = mod_c;
		output->size += add_size;
	}
}

void	s_null_case(t_output *output, t_arg_spec *spec)
{
	if (spec->param.prec < 0 || spec->param.prec > 5)
		output->to_print = ft_strdup("(null)");
	else
		output->to_print = ft_strdup("");
	output->size = ft_strlen(output->to_print);
}

void	prec_smod(t_output *output, t_arg_spec *spec)
{
	ssize_t	len;
	char	*tr_str;
	int		i;

	if (!output->to_print)
		return (s_null_case(output, spec), (void)0);
	len = ft_strlen(output->to_print);
	if (len < spec->param.prec || spec->param.prec < 0)
		return ;
	tr_str = malloc(spec->param.prec + 1);
	if (!tr_str)
		return ;
	i = 0;
	while (i < spec->param.prec && i < len)
	{
		tr_str[i] = (output->to_print)[i];
		i++;
	}
	tr_str[i] = 0;
	free(output->to_print);
	output->to_print = tr_str;
	output->size = spec->param.prec;
}

void	prec_nmod(t_output *output, t_arg_spec *spec)
{
	char	*add;
	ssize_t	add_size;

	if (!output->to_print || spec->param.prec < 0)
		return ;
	if (spec->param.prec == 0 && *(output->to_print) == '0')
	{
		free(output->to_print);
		output->to_print = ft_strdup("");
		output->size = 0;
		return ;
	}
	add_size = spec->param.prec - output->size;
	if (*(output->to_print) == '-')
		add_size++;
	if (add_size > 0)
	{
		add = ft_setalloc(sizeof(char) * (add_size + 1), '0', 1);
		if (*(output->to_print) == '-')
			output->to_print = ft_strinsert_free(output->to_print, add, 1);
		else
			output->to_print = ft_strinsert_free(output->to_print, add, 0);
		output->size = ft_strlen(output->to_print);
	}
}
