/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:43:28 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 01:14:08 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ftfpr_parse_args(va_list args, const char *fmt, int fd);
static int	ftfpr_check_fmt(const char *fmt);

/* FT_FPRINTF! Supports "diucspxXX" with "0# .-+" & prec & width. */
int	ft_fprintf(int fd, const char *fmt, ...)
{
	va_list	args;
	int		chars_printed;

	if (!fmt || !ftfpr_check_fmt(fmt))
		return (-1);
	if (!*fmt)
		return (0);
	if (fd < 0)
		return (-1);
	va_start(args, fmt);
	chars_printed = ftfpr_parse_args(args, fmt, fd);
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
static int	ftfpr_check_fmt(const char *fmt)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (ftfpr_compl_isconv(fmt) == -1)
				return (0);
			while (ftfpr_isflagconv(*(++fmt)) != 1)
				;
		}
		fmt++;
	}
	return (1);
}

/* Parse args while scanning fmtstring. Returns number of printed chars. */
static int	ftfpr_parse_args(va_list args, const char *fmt, int fd)
{
	int	c;
	int	output;

	output = 0;
	while (*fmt)
	{
		c = ftfpr_is_conversion(fmt);
		if (c == 1)
			fmt += ftfpr_smpl_convert(args, fmt, &output, fd);
		else if (c == -1)
		{
			c = ftfpr_gather_flags_and_conv(args, fmt, &output, fd);
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
