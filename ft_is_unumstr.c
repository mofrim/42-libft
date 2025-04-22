/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unumstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:49:48 by fmaurer           #+#    #+#             */
/*   Updated: 2025/04/22 22:14:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if numstr is a valid floating point or integer number without any
 * leading +/- signs. '.0' or '12.' strings return false! */
bool	ft_is_unumstr(char	*s)
{
	size_t	i;

	if (!s || (s && !*s))
		return (false);
	i = 0;
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
