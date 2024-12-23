/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:43:28 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/23 18:22:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	ftdpr_parse_args(va_list args, const char *fmt, int fd);
static int	ftdpr_check_fmt(const char *fmt);

/* FT_dprintf! Supports "diucspxXX" with "0# .-+" & prec & width. */
int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	args;
	int		chars_printed;

	if (!fmt || !ftdpr_check_fmt(fmt))
		return (-1);
	if (!*fmt)
		return (0);
	if (fd < 0)
		return (-1);
	va_start(args, fmt);
	chars_printed = ftdpr_parse_args(args, fmt, fd);
	va_end(args);
	return (chars_printed);
}

/*
 * Checks for INVALID conversions.
 *
 * Cases for this: Conversion running off the strings end. To >INT_MAX prec or
 * width numbers.
 * 
 */
static int	ftdpr_check_fmt(const char *fmt)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (ftdpr_compl_isconv(fmt) == -1)
				return (0);
			while (ftdpr_isflagconv(*(++fmt)) != 1)
				;
		}
		fmt++;
	}
	return (1);
}

/* Parse args while scanning fmtstring. Returns number of printed chars. */
static int	ftdpr_parse_args(va_list args, const char *fmt, int fd)
{
	int	c;
	int	output;

	output = 0;
	while (*fmt)
	{
		c = ftdpr_is_conversion(fmt);
		if (c == 1)
			fmt += ftdpr_smpl_convert(args, fmt, &output, fd);
		else if (c == -1)
		{
			c = ftdpr_gather_flags_and_conv(args, fmt, &output, fd);
			if (c < 0)
				return (-1);
			fmt += c;
		}
		else
		{
			ft_putchar_fd(*fmt, fd);
			output++;
			fmt++;
		}
	}
	return (output);
}
