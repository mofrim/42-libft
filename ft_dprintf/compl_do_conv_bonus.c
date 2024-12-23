/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_do_conv_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:50:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/23 18:22:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	percent(int fd);

/*
 * Finally really do the conversion.
 *
 * Does the conversion specified in param char conv. The number of printed chars
 * is saved in param int output which will finally be returned from
 * ftdpr_parse_args to main ft_printf func.
 *
 */
int	ftdpr_compl_do_conv(va_list args, char conv, t_flags *flags, int fd)
{
	int	outp;

	outp = 0;
	if (conv == '%')
		outp = percent(fd);
	else if (conv == 'd' || conv == 'i')
		outp = ftdpr_compl_converter_d(va_arg(args, int), flags, fd);
	else if (conv == 'u')
		outp = ftdpr_compl_converter_u(va_arg(args, unsigned int), flags, fd);
	else if (conv == 'c')
		outp = ftdpr_compl_converter_c(va_arg(args, int), flags, fd);
	else if (conv == 's')
		outp = ftdpr_compl_converter_s(va_arg(args, char *), flags, fd);
	else if (conv == 'p')
		outp = ftdpr_compl_converter_p(va_arg(args, unsigned long), flags, fd);
	else if (conv == 'x' || conv == 'X')
		outp = ftdpr_compl_converter_x(va_arg(args, unsigned int),
				flags, conv, fd);
	return (outp);
}

/* The sinplest conv ever.
 *
 * Still we need this here because there might be any agglomeration of valid
 * flags in between the first % and the final one.
 *
 */
static int	percent(int fd)
{
	ft_putchar_fd('%', fd);
	return (1);
}
