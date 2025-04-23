/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_uinumstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:49:48 by fmaurer           #+#    #+#             */
/*   Updated: 2025/04/23 00:34:48 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if numstr is a valid integer number without any leading +/- signs.
 * Strings like '01', or '00023' with one or more zeros at the beginning are
 * considered invalid. */
bool	ft_is_uinumstr(char	*s)
{
	size_t	i;

	if (!s || (s && !*s))
		return (false);
	if (s[0] == '0' && ft_strlen(s) > 1)
		return (false);
	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (false);
	return (true);
}
