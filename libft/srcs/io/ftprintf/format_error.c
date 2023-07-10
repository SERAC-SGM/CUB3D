/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnam <matnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:50:49 by maaliber          #+#    #+#             */
/*   Updated: 2023/05/13 17:55:54 by matnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	err_msg_ftp(char *msg, int c)
{
	write(1, BRED, 9);
	write(1, "error: ", 7);
	write(1, RESET, 4);
	write(1, msg, ft_strlen(msg));
	if (ft_isprint(c))
	{
		write(1, BWHITE, 9);
		write(1, " '%", 3);
		write(1, &c, 1);
		write(1, RESET, 4);
	}
	write(1, "'\n", 2);
}

int	flag_comp_err(t_arg_spec *spec)
{
	if (spec->param.alt && !ft_ischarset(spec->type, "xX"))
		return (err_msg_ftp("'#' flag used with", spec->type), 1);
	else if (spec->param.space && !ft_ischarset(spec->type, "sdi"))
		return (err_msg_ftp("' ' flag used with", spec->type), 1);
	else if (spec->param.showsign && !ft_ischarset(spec->type, "di"))
		return (err_msg_ftp("'+' flag used with", spec->type), 1);
	else if (spec->param.prec >= 0 && !ft_ischarset(spec->type, "sdiuxX"))
		return (err_msg_ftp("precision used with", spec->type), 1);
	return (0);
}

void	flag_err_msg(int errno)
{
	write(1, BRED, 9);
	write(1, "error: ", 7);
	write(1, RESET, 4);
	if (errno == 1)
		write(1, "repeated '#' flag\n", 18);
	else if (errno == 2)
		write(1, "repeated '-' flag\n", 18);
	else if (errno == 3)
		write(1, "repeated '0' flag\n", 18);
	else if (errno == 4)
		write(1, "repeated '+' flag\n", 18);
	else if (errno == 5)
		write(1, "repeated ' ' flag\n", 18);
	else if (errno == 6)
		write(1, "'0' flag is ignored when '-' flag is present\n", 45);
	else if (errno == 7)
		write(1, "' ' flag is ignored when '+' flag is present\n", 45);
	else if (errno == 8)
		write(1, "'0' flag is ignored with precision\n", 35);
}

int	flag_error(t_arg_spec *spec)
{
	if (spec->param.alt > 1)
		return (flag_err_msg(1), 1);
	else if (spec->param.left > 1)
		return (flag_err_msg(2), 1);
	else if (spec->param.padded > 1)
		return (flag_err_msg(3), 1);
	else if (spec->param.showsign > 1)
		return (flag_err_msg(4), 1);
	else if (spec->param.space > 1)
		return (flag_err_msg(5), 1);
	else if (spec->param.left && spec->param.padded)
		return (flag_err_msg(6), 1);
	else if (spec->param.showsign && spec->param.space)
		return (flag_err_msg(7), 1);
	else if (spec->param.prec >= 0 && spec->param.padded)
		return (flag_err_msg(8), 1);
	return (0);
}

int	ft_format_error(t_lst_arg *arg, char *sup_types)
{
	while (arg)
	{
		if (arg->spec->type == 0)
			return (err_msg_ftp("spurious trailing ‘%’ in format", 0), 1);
		if (ft_index(sup_types, arg->spec->type) < 0)
		{
			err_msg_ftp("unknown conversion type character", arg->spec->type);
			return (1);
		}
		if (flag_comp_err(arg->spec))
			return (1);
		arg = arg->next;
	}
	return (0);
}
