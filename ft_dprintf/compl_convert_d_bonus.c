/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_d_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/23 18:22:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	print_left_padded(int d, t_flags *fl, int fd);

static int	print_right_padded(int d, t_flags *fl, int fd);

static int	print_prec(int d, t_flags *fl, int fd);

static int	print_prec_width(int d, t_flags *fl, int nlen, int fd);

/* Convert integer with flags. */
int	ftdpr_compl_converter_d(int d, t_flags *fl, int fd)
{
	int	r;

	r = 0;
	if (!fl->minus && !fl->dot && (fl->zero || fl->plus || fl->space \
		|| fl->width))
		r = print_left_padded(d, fl, fd);
	else if (fl->minus && !fl->dot)
		r = print_right_padded(d, fl, fd);
	else if (fl->dot && (fl->prec >= fl->width))
		r = print_prec(d, fl, fd);
	else if (fl->dot && (fl->prec < fl->width))
		r = print_prec_width(d, fl, ftdpr_intstrlen(d), fd);
	return (r);
}

/* Helper function. Print left padded. */
static int	print_left_padded(int d, t_flags *fl, int fd)
{
	char	*numstr;
	int		i;
	int		len;

	numstr = ft_itoa(d);
	len = ft_strlen(numstr);
	i = -1;
	if (d < 0 && fl->zero)
		ft_putchar_fd('-', fd);
	if (d >= 0 && (fl->plus || fl->space) && fl->zero)
		ft_putchar_fd(fl->plus * '+' + fl->space * ' ', fd);
	if (fl->width > len)
		while (++i < fl->width - len - (d >= 0 && (fl->plus || fl->space)))
			ft_putchar_fd(fl->zero * '0' + !fl->zero * ' ', fd);
	if (d >= 0 && (fl->plus || fl->space) && !fl->zero)
		ft_putchar_fd(fl->plus * '+' + fl->space * ' ', fd);
	if (d < 0)
		ft_putstr_fd(numstr + 1 * fl->zero, fd);
	else
		ft_putstr_fd(numstr, fd);
	free(numstr);
	if (fl->width >= len + ((fl->plus || fl->space) && (d >= 0)))
		return (fl->width);
	return (len + ((fl->plus || fl->space) && (d >= 0)));
}

/* Helper function. Print right padded. */
static int	print_right_padded(int d, t_flags *fl, int fd)
{
	char	*numstr;
	int		i;
	int		len;

	numstr = ft_itoa(d);
	len = ft_strlen(numstr);
	i = -1;
	if (d >= 0 && (fl->plus || fl->space))
	{
		ft_putchar_fd(fl->plus * '+' + fl->space * ' ', fd);
		i++;
	}
	ft_putstr_fd(numstr, fd);
	if (fl->width && fl->width > len)
		while (++i < fl->width - len)
			ft_putchar_fd(' ', fd);
	free(numstr);
	if (fl->width > len)
		return (fl->width);
	return (len + ((fl->space || fl->plus) && (d >= 0)));
}

/* Helper function. Print with precission. */
static int	print_prec(int d, t_flags *fl, int fd)
{
	char	*numstr;
	int		i;
	int		len;

	numstr = ft_itoa(d);
	len = ft_strlen(numstr);
	i = -1;
	if (!d && !fl->prec)
		return (0);
	if (d < 0)
		ft_putchar_fd('-', fd);
	if (d >= 0 && (fl->plus || fl->space))
		ft_putchar_fd(fl->plus * '+' + fl->space * ' ', fd);
	if (fl->prec > len - (d < 0))
		while (++i < fl->prec - len + (d < 0))
			ft_putchar_fd('0', fd);
	if (d < 0)
		ft_putstr_fd(numstr + 1, fd);
	else
		ft_putstr_fd(numstr, fd);
	free(numstr);
	if (fl->prec >= len)
		return (fl->prec + ((fl->plus || fl->space) && (d >= 0)) + (d < 0));
	return (len + ((fl->plus || fl->space) && (d >= 0)));
}

/* Helper function. Print with precission & width. 
 *
 * The @param nlen is hold the strlen of the number converted to ascii string.
 * Which actually is a bit of a codelen hack.
 *
 */
static int	print_prec_width(int d, t_flags *fl, int nlen, int fd)
{
	int		i;
	int		r;
	int		sublen;

	i = -1;
	nlen -= (d < 0) + (!d);
	sublen = fl->prec * (nlen < fl->prec) + nlen * (nlen >= fl->prec);
	if (d < 0 || fl->plus || fl->space)
		fl->width--;
	if (!fl->minus)
	{
		while (++i < fl->width - sublen)
			ft_putchar_fd(' ', fd);
		r = print_prec(d, fl, fd) + i;
	}
	else
	{
		r = print_prec(d, fl, fd);
		while (++i < fl->width - sublen)
			ft_putchar_fd(' ', fd);
		r += i;
	}
	return (r);
}
