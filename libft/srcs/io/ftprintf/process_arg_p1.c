/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_p1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:18:57 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/17 16:14:47 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_char(t_output *output, va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	output->to_print = malloc(1);
	if (!output->to_print)
		return ;
	output->to_print[0] = c;
	output->size = 1;
}

void	p_str(t_output *output, va_list ap)
{
	char	*s;

	s = (char *)va_arg(ap, char *);
	if (!s)
		return ;
	output->size = ft_strlen(s);
	output->to_print = malloc(sizeof(char) * output->size + 1);
	if (!output->to_print)
		return ;
	ft_strlcpy(output->to_print, s, output->size + 1);
}

void	p_ptr(t_output *output, va_list ap)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(ap, void *);
	if (!ptr)
	{
		output->size = 5;
		output->to_print = ft_strdup("(nil)");
		return ;
	}
	output->to_print = ft_utoa_base(ptr, "0123456789abcdef");
	output->to_print = ft_strjoin_free(ft_strdup("0x"), output->to_print);
	output->size = ft_strlen(output->to_print);
}

void	p_int(t_output *output, va_list ap)
{
	int	i;

	i = (int)va_arg(ap, int);
	output->to_print = ft_itoa(i);
	output->size = ft_strlen(output->to_print);
}

void	p_uint(t_output *output, va_list ap)
{
	unsigned int	n;

	n = (unsigned int)va_arg(ap, unsigned int);
	output->to_print = ft_utoa(n);
	output->size = ft_strlen(output->to_print);
}
