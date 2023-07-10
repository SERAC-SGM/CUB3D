/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:19:02 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_hex(t_output *output, va_list ap)
{
	unsigned int	x;

	x = (unsigned int)va_arg(ap, unsigned int);
	output->to_print = ft_utoa_base(x, "0123456789abcdef");
	output->size = ft_strlen(output->to_print);
}

void	p_uphex(t_output *output, va_list ap)
{
	unsigned int	x;

	x = (unsigned int)va_arg(ap, unsigned int);
	output->to_print = ft_utoa_base(x, "0123456789ABCDEF");
	output->size = ft_strlen(output->to_print);
}

void	p_pct(t_output *output, va_list ap)
{
	(void)ap;
	output->to_print = ft_strdup("%");
	output->size = 1;
}
