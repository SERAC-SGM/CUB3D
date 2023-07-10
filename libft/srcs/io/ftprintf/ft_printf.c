/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:45:01 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	static const char	*sup_types = "cspdiuxX%";
	va_list				ap;
	t_lst_arg			*arg_list;
	ssize_t				w_bytes;

	arg_list = ft_parse_format(format);
	if (!arg_list && find_next_fmt(format))
		return (-1);
	if (ft_format_error(arg_list, (char *)sup_types))
		return (ft_lstclear_arg(&arg_list), -1);
	va_start (ap, format);
	w_bytes = ft_output(format, ap, arg_list);
	va_end (ap);
	ft_lstclear_arg(&arg_list);
	return (w_bytes);
}
