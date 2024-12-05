/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:52:03 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 01:14:27 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

/* Is current conv string a smpl conv? */
int	ftfpr_smpl_isconv(const char *s)
{
	if (!ft_strncmp(s, "%c", 2) || !ft_strncmp(s, "%s", 2) || \
		!ft_strncmp(s, "%p", 2) || !ft_strncmp(s, "%d", 2) || \
		!ft_strncmp(s, "%i", 2) || !ft_strncmp(s, "%u", 2) || \
		!ft_strncmp(s, "%x", 2) || !ft_strncmp(s, "%X", 2) || \
		!ft_strncmp(s, "%%", 2))
		return (1);
	return (0);
}

/* Calls the actual conversion functions. In smpl case always returns 2. */
int	ftfpr_smpl_convert(va_list args, const char *s, int *r, int fd)
{
	if (!ft_strncmp(s, "%c", 2))
		*r += ftfpr_converter_c(va_arg(args, int), fd);
	if (!ft_strncmp(s, "%s", 2))
		*r += ftfpr_converter_s(va_arg(args, char *), fd);
	if (!ft_strncmp(s, "%p", 2))
		*r += ftfpr_converter_p(va_arg(args, unsigned long), fd);
	if (!ft_strncmp(s, "%d", 2))
		*r += ftfpr_converter_d(va_arg(args, int), fd);
	if (!ft_strncmp(s, "%i", 2))
		*r += ftfpr_converter_d(va_arg(args, int), fd);
	if (!ft_strncmp(s, "%u", 2))
		*r += ftfpr_converter_u(va_arg(args, unsigned int), fd);
	if (!ft_strncmp(s, "%x", 2))
		*r += ftfpr_converter_x(va_arg(args, int), 0, fd);
	if (!ft_strncmp(s, "%X", 2))
		*r += ftfpr_converter_x(va_arg(args, int), 1, fd);
	if (!ft_strncmp(s, "%%", 2))
		*r += ftfpr_converter_c('%', fd);
	return (2);
}
