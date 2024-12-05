/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_s_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 01:11:29 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	print_left_padded(char *s, t_flags *fl, int fd);

static int	print_right_padded(char *s, t_flags *fl, int fd);

static int	print_prec(char *s, t_flags *fl, int fd);

static int	print_prec_width(char *s, t_flags *fl, int fd);

/* Convert string with flags "-." prec and width. */
int	ftfpr_compl_converter_s(char *s, t_flags *fl, int fd)
{
	int	r;

	r = 0;
	if (!fl->minus && !fl->dot && fl->width)
		r = print_left_padded(s, fl, fd);
	else if (fl->minus && !fl->dot)
		r = print_right_padded(s, fl, fd);
	else if (fl->dot)
		r = print_prec_width(s, fl, fd);
	else
		return (ftfpr_converter_s(s, fd));
	return (r);
}

/* Helper function. Print left padded. */
static int	print_left_padded(char *s, t_flags *fl, int fd)
{
	int		i;
	int		len;

	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	i = -1;
	if (fl->width > len)
		while (++i < fl->width - len)
			ft_putchar_fd(' ', fd);
	ftfpr_converter_s(s, fd);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

/* Helper function. Print right padded. */
static int	print_right_padded(char *s, t_flags *fl, int fd)
{
	int		i;
	int		len;

	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	i = -1;
	ftfpr_converter_s(s, fd);
	if (fl->width > len)
		while (++i < fl->width - len)
			ft_putchar_fd(' ', fd);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

/* Helper function. Print with precission. */
static int	print_prec(char *s, t_flags *fl, int fd)
{
	int		i;
	int		len;

	if (!s)
	{
		if (fl->prec >= 6)
			return (ftfpr_converter_s(s, fd));
		else
			return (0);
	}
	else
		len = ft_strlen(s);
	i = -1;
	if (fl->prec < len)
		while (++i < fl->prec)
			ft_putchar_fd(*s++, fd);
	else
		ftfpr_converter_s(s, fd);
	if (fl->prec < len)
		return (fl->prec);
	return (len);
}

/* Helper function. Print with precission & width. 
 *
 * ("%7.7s", NULL) -> outp = ' (null)', ret = 7
 * ("%.7s", NULL) -> outp = '(null)', ret = 6
 * ("%.5s", NULL) -> outp = '', ret = 0
 * ("%7.5s", NULL) -> outp = '       ', ret = 7
 * */
static int	print_prec_width(char *s, t_flags *fl, int fd)
{
	int		i;
	int		r;
	int		len;

	i = -1;
	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	if (!fl->minus)
	{
		while (++i < fl->width - fl->prec * ((fl->prec < len) && s != NULL) - \
				len * (fl->prec >= len))
			ft_putchar_fd(' ', fd);
		r = print_prec(s, fl, fd) + i;
	}
	else
	{
		r = print_prec(s, fl, fd);
		while (++i < fl->width - r)
			ft_putchar_fd(' ', fd);
		r += i;
	}
	return (r);
}
