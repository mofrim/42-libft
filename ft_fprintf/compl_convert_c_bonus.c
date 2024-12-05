/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_c_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 01:10:50 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	print_right_padded(int c, t_flags *fl, int fd);

static int	print_left_padded(int c, t_flags *fl, int fd);

/*
 * Width flag aware conversion of char.
 *
 * @param c The char to be put out
 * @param fl The t_flags struct with all the flags requested
 *
 * @return Returns number of printed chars
 */
int	ftfpr_compl_converter_c(int c, t_flags *fl, int fd)
{
	int	r;

	r = 0;
	if (fl->minus)
		r = print_right_padded(c, fl, fd);
	else if (!fl->minus)
		r = print_left_padded(c, fl, fd);
	return (r);
}

/* Helper func. Print right padded. */
static int	print_right_padded(int c, t_flags *fl, int fd)
{
	int		i;

	i = -1;
	ft_putchar_fd(c, fd);
	if (fl->width)
		while (++i < fl->width - 1)
			ft_putchar_fd(' ', fd);
	if (fl->width)
		return (fl->width);
	return (1);
}

/* Helper func. Print left padded. */
static int	print_left_padded(int c, t_flags *fl, int fd)
{
	int		i;

	i = -1;
	while (++i < fl->width - 1)
		ft_putchar_fd(' ', fd);
	ft_putchar_fd(c, fd);
	if (fl->width)
		return (fl->width);
	return (1);
}
