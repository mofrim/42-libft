/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 07:44:49 by fmaurer           #+#    #+#             */
/*   Updated: 2025/03/14 17:22:23 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Convert ascii string to integer. A *single* minus or plus is counted.
 * Everything else afterwards which is not a digit will be considered garbage
 * and lead to return value 0. Even INT_MIN is handled easily because somehow
 * -(214748364 * 10 + 8) = INT_MIN automagically! */
int	ft_atoi(const char *s)
{
	int	num;
	int	sgn;

	num = 0;
	sgn = 1;
	if (!s)
		return (0);
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		sgn = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		num = num * 10 + *s++ - '0';
	return (num * sgn);
}
