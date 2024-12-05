/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_p_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 01:11:14 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	print_left_padded(unsigned long p, t_flags *fl, int fd);

static int	print_right_padded(unsigned long p, t_flags *fl, int fd);

/* Convert mem adress. */
int	ftfpr_compl_converter_p(unsigned long p, t_flags *fl, int fd)
{
	int	r;

	r = 0;
	if (!fl->minus && fl->width)
		r = print_left_padded(p, fl, fd);
	else if (fl->minus)
		r = print_right_padded(p, fl, fd);
	else
		return (ftfpr_converter_p(p, fd));
	return (r);
}

/* Helper function. Print left padded. */
static int	print_left_padded(unsigned long p, t_flags *fl, int fd)
{
	int		i;
	int		len;

	len = (p != 0) * (ftfpr_hex_digits(p) + 2) + (!p) * 5;
	i = -1;
	if (fl->width > len)
		while (++i < fl->width - len)
			ft_putchar_fd(' ', fd);
	ftfpr_converter_p(p, fd);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

/* Helper function. Print right padded. */
static int	print_right_padded(unsigned long p, t_flags *fl, int fd)
{
	int		i;
	int		len;

	len = (p != 0) * (ftfpr_hex_digits(p) + 2) + (!p) * 5;
	i = -1;
	ftfpr_converter_p(p, fd);
	if (fl->width > len)
		while (++i < fl->width - len)
			ft_putchar_fd(' ', fd);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}
