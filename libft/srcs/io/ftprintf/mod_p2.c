/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_p2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:33:15 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	padded_mod(t_output *output, t_arg_spec *spec)
{
	char	*add;
	ssize_t	add_size;

	if (!output->to_print || spec->param.prec >= 0)
		return ;
	add_size = spec->param.width - output->size;
	if (ft_ischarset(spec->type, "xX")
		&& *(output->to_print) != '0' && spec->param.alt)
		add_size -= 2;
	if (spec->param.padded && add_size > 0)
	{
		add = ft_setalloc(sizeof(char) * (add_size + 1), '0', 1);
		if (!add)
			return ;
		if (*(output->to_print) == '-')
			output->to_print = ft_strinsert_free(output->to_print, add, 1);
		else
			output->to_print = ft_strinsert_free(output->to_print, add, 0);
	}
	output->size = ft_strlen(output->to_print);
}

void	alt_mod(t_output *output, t_arg_spec *spec)
{
	char	*add;

	if (!output->to_print)
		return ;
	if (spec->param.alt > 0)
	{
		if (spec->type == 'x'
			&& ft_atoi_base(output->to_print, "0123456789abcdef"))
			add = ft_strdup("0x");
		else if (spec->type == 'X'
			&& ft_atoi_base(output->to_print, "0123456789ABCDEF"))
			add = ft_strdup("0X");
		else
			return ;
		output->to_print = ft_strjoin_free(add, output->to_print);
		output->size = ft_strlen(output->to_print);
	}
}

void	sign_space_mod(t_output *output, t_arg_spec *spec)
{
	char	*add;

	if (!output->to_print || *(output->to_print) == '-')
		return ;
	if (spec->param.showsign > 0)
	{
		add = ft_strdup("+");
		output->to_print = ft_strjoin_free(add, output->to_print);
	}
	else if (spec->param.space > 0)
	{
		add = ft_strdup(" ");
		output->to_print = ft_strjoin_free(add, output->to_print);
	}
	output->size = ft_strlen(output->to_print);
}

void	left_width_mod(t_output *output, t_arg_spec *spec)
{
	char	*add;
	ssize_t	add_size;

	if (!output->to_print)
		return ;
	add_size = spec->param.width - output->size;
	if (add_size > 0)
	{
		add = ft_setalloc(sizeof(char) * (add_size + 1), ' ', 1);
		if (spec->param.left)
			output->to_print = ft_strjoin_free(output->to_print, add);
		else
			output->to_print = ft_strjoin_free(add, output->to_print);
		output->size = ft_strlen(output->to_print);
	}
}
