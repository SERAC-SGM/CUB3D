/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:53:52 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	spec_mod(t_output *output, t_arg_spec *spec)
{
	if (spec->type == 'c')
		ctype_mod(output, spec);
	if (spec->type == 's')
		prec_smod(output, spec);
	if (ft_ischarset(spec->type, "diuxX"))
		prec_nmod(output, spec);
	if (ft_ischarset(spec->type, "diuxX"))
		padded_mod(output, spec);
	if (ft_ischarset(spec->type, "xX"))
		alt_mod(output, spec);
	if (ft_ischarset(spec->type, "di"))
		sign_space_mod(output, spec);
	if (ft_ischarset(spec->type, "spdiuxX"))
		left_width_mod(output, spec);
	return ;
}

ssize_t	write_arg(va_list ap, t_arg_spec *spec)
{
	static void	(*process_arg[9])(t_output*, va_list)
		= {p_char, p_str, p_ptr, p_int, p_int, p_uint, p_hex, p_uphex, p_pct};
	static char	*sup_types = "cspdiuxX%";
	ssize_t		idx;
	t_output	*output;
	ssize_t		wbytes;

	output = ft_calloc(1, sizeof(t_output));
	if (!output)
		return (0);
	idx = ft_index(sup_types, spec->type);
	if (idx < 0)
		return (free(output), 0);
	process_arg[idx](output, ap);
	if (!output->to_print && !(spec->type == 's' && output->size == 0))
		return (free(output), 0);
	spec_mod(output, spec);
	wbytes = output->size;
	write(1, output->to_print, wbytes);
	return (free(output->to_print), free(output), wbytes);
}

ssize_t	ft_output(const char *fmt, va_list ap, t_lst_arg *arg_list)
{
	const char	*f;
	ssize_t		wbytes;

	wbytes = 0;
	f = find_next_fmt(fmt);
	while (*fmt && f)
	{
		wbytes += write(1, fmt, f - fmt);
		wbytes += write_arg(ap, arg_list->spec);
		fmt = f + arg_list->spec->size;
		arg_list = arg_list->next;
		f = find_next_fmt(fmt);
	}
	wbytes += write(1, fmt, ft_strlen(fmt));
	return (wbytes);
}
