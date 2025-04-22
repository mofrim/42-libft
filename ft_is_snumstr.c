/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_snumstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:45:45 by fmaurer           #+#    #+#             */
/*   Updated: 2025/04/22 22:14:34 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if numstr is a valid floating point or integer number with optionally
 * one leading plus or minus sign. */
bool	ft_is_snumstr(char *s)
{
	size_t	i;
	short	sgn;

	i = 0;
	sgn = 0;
	if (!s || (s && !*s))
		return (false);
	if (s[0] == '+' || s[0] == '-')
		sgn = ++i;
	if (sgn && (!s[1] || (s[1] && !ft_isdigit(s[1]))))
		return (false);
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '.' && (!s[i + 1] || i == 0))
		return (false);
	if (s[i] == '.' && s[i + 1])
		while (s[++i])
			if (!ft_isdigit(s[i]))
				return (false);
	if (!s[i])
		return (true);
	return (false);
}
