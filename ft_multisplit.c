/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multisplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:20:54 by fmaurer           #+#    #+#             */
/*   Updated: 2025/04/22 10:25:38 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This is a wrapper for _ft_multisplit which moves the strlen calculation of
 * splitchars into the function. This wasn't possible due to norminette in the
 * _ft_multisplit func. */

char	**_ft_multisplit(char const *s, char *splitchars, size_t sclen);

/**
 * Split string s by a splitchar chracterset.
 *
 * Example:
 * 		ft_multisplit("abc.defg;hij'", ".;'") -> {"abc", "defg", "hij"}
 * Returns: NULL terminated array of strings.
 */
char	**ft_multisplit(char const *s, char *splitchars)
{
	return (_ft_multisplit(s, splitchars, ft_strlen(splitchars)));
}
