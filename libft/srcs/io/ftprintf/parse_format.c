/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:38:38 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	atoi_printf(const char *nstr, t_arg_spec *spec)
{
	int	n;

	n = 0;
	while (*nstr >= '0' && *nstr <= '9')
	{
		n = n * 10 + (*nstr++ - '0');
		spec->size++;
	}
	return (n);
}

const char	*find_next_fmt(const char *format)
{
	return (ft_strchr(format, '%'));
}

int	init_option(t_arg_spec	*spec, const char *fmt)
{
	fmt++;
	spec->param.prec = -1;
	while (ft_ischarset(*(fmt), "-0+ #"))
	{
		if (*fmt == '-')
			spec->param.left++;
		else if (*fmt == '0')
			spec->param.padded++;
		else if (*fmt == '+')
			spec->param.showsign++;
		else if (*fmt == ' ')
			spec->param.space++;
		else if (*fmt == '#')
			spec->param.alt++;
		spec->size++;
		fmt++;
	}
	return (1);
}

t_arg_spec	*init_arg(const char *fmt)
{
	t_arg_spec	*spec;

	spec = ft_calloc(1, sizeof(t_arg_spec));
	if (!spec)
		return (NULL);
	spec->size = 1;
	if (!init_option(spec, fmt))
		return (free(spec), NULL);
	spec->param.width = atoi_printf(fmt + spec->size, spec);
	if (*(fmt + spec->size) == '.')
	{
		spec->size++;
		spec->param.prec = atoi_printf(fmt + spec->size, spec);
	}
	spec->type = *(fmt + spec->size++);
	return (spec);
}

t_lst_arg	*ft_parse_format(const char *fmt)
{
	t_lst_arg	*arg_list;
	t_lst_arg	*arg;
	t_arg_spec	*spec;
	const char	*f = (const char *) fmt;

	arg_list = NULL;
	f = find_next_fmt(fmt);
	while (f)
	{
		spec = init_arg(f);
		if (!spec)
			return (ft_lstclear_arg(&arg_list), NULL);
		arg = ft_lstnew_arg(spec);
		if (!arg)
			return (ft_lstclear_arg(&arg_list), free(spec), NULL);
		ft_lstadd_back_arg(&arg_list, arg);
		f = find_next_fmt(f + spec->size);
	}
	return (arg_list);
}
