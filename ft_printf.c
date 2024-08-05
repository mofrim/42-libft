/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:43:28 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/05 19:36:55 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* FT_PRINTF! Supports "diucspxXX" with "0# .-+" & prec & width. */
int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		chars_printed;

	if (!fmt || !ftpr_check_fmt(fmt))
		return (-1);
	if (!*fmt)
		return (0);
	va_start(args, fmt);
	chars_printed = ftpr_parse_args(args, fmt);
	va_end(args);
	return (chars_printed);
}
