/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitesplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:18:41 by fmaurer           #+#    #+#             */
/*   Updated: 2025/04/22 11:20:26 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Split a string by all possible whitespace chars. Return the split. */
char	**ft_whitesplit(char *s)
{
	return (ft_multisplit(s, " \t\v\f\n\r"));
}
