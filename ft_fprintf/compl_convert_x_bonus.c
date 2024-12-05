/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_x_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 01:12:47 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	print_left_padded(unsigned int i, t_flags *fl, int c, int fd);

static int	print_right_padded(unsigned int i, t_flags *fl, int c, int fd);

static int	print_prec(unsigned int i, t_flags *fl, int c, int fd);

static int	print_prec_width(unsigned int i, t_flags *fl, int c, int fd);

/* Convert to hex with "-. 0" flags. */
int	ftfpr_compl_converter_x(unsigned int i, t_flags *fl, int c, int fd)
{
	int	r;

	r = 0;
	if (!fl->minus && !fl->dot && fl->width)
		r = print_left_padded(i, fl, c, fd);
	else if (fl->minus && !fl->dot)
		r = print_right_padded(i, fl, c, fd);
	else if (fl->dot)
		r = print_prec_width(i, fl, c, fd);
	else
	{
		ftfpr_print_zerox(fl->hash, c, i, fd);
		if (c == 'x')
			return (ftfpr_converter_x(i, 0, fd) + 2 * (i != 0) * fl->hash);
		else
			return (ftfpr_converter_x(i, 1, fd) + 2 * (i != 0) * fl->hash);
	}
	return (r);
}

/* Helper function. Print left padded. */
static int	print_left_padded(unsigned int i, t_flags *fl, int c, int fd)
{
	int		k;
	int		len;

	len = (i != 0) * (ftfpr_hex_digits(i) + fl->hash * 2) + (!i);
	k = -1;
	if (fl->zero && fl->hash)
		ftfpr_print_zerox(fl->hash, c, i, fd);
	if (fl->width > len)
		while (++k < fl->width - len)
			ft_putchar_fd(!fl->zero * ' ' + fl->zero * '0', fd);
	if (!(fl->zero && fl->hash))
		ftfpr_print_zerox(fl->hash, c, i, fd);
	if (c == 'x')
		ftfpr_converter_x(i, 0, fd);
	else
		ftfpr_converter_x(i, 1, fd);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

/* Helper function. Print right padded. */
static int	print_right_padded(unsigned int i, t_flags *fl, int c, int fd)
{
	int		k;
	int		len;

	len = ftfpr_hex_digits(i) + (i != 0) * fl->hash * 2;
	k = -1;
	ftfpr_print_zerox(fl->hash, c, i, fd);
	if (c == 'x')
		ftfpr_converter_x(i, 0, fd);
	else
		ftfpr_converter_x(i, 1, fd);
	if (fl->width > len)
		while (++k < fl->width - len)
			ft_putchar_fd(' ', fd);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

/* Helper function. Print with precission. */
static int	print_prec(unsigned int i, t_flags *fl, int c, int fd)
{
	int		k;
	int		len;

	len = ftfpr_hex_digits(i);
	k = -1;
	if (i == 0 && !fl->prec)
		return (0);
	if ((fl->prec < len) && (c == 'x'))
		ftfpr_converter_x(i, 0, fd);
	else if ((fl->prec < len) && (c == 'X'))
		ftfpr_converter_x(i, 1, fd);
	else
	{
		while (++k < fl->prec - len)
			ft_putchar_fd('0', fd);
		if (c == 'x')
			ftfpr_converter_x(i, 0, fd);
		else
			ftfpr_converter_x(i, 1, fd);
	}
	if (fl->prec < len)
		return (len);
	return (fl->prec);
}

/* Helper function. Print with precission & width. */
static int	print_prec_width(unsigned int i, t_flags *fl, int c, int fd)
{
	int		k;
	int		r;
	int		len;

	k = -1;
	len = (!i) * fl->prec + (i != 0) * ftfpr_hex_digits(i);
	if (!fl->minus)
	{
		while (++k < fl->width - (fl->prec + (i != 0) * fl->hash * 2) \
				* (fl->prec >= len) - (len + (i != 0) * fl->hash * 2) \
				* (fl->prec < len))
			ft_putchar_fd(' ', fd);
		ftfpr_print_zerox(fl->hash, c, i, fd);
		r = print_prec(i, fl, c, fd) + k;
		r += (i != 0) * 2 * fl->hash;
	}
	else
	{
		ftfpr_print_zerox(fl->hash, c, i, fd);
		r = print_prec(i, fl, c, fd);
		while (++k < fl->width - (r + fl->hash * 2 * (i != 0)))
			ft_putchar_fd(' ', fd);
		r += k + (i != 0) * (fl->hash * 2);
	}
	return (r);
}
