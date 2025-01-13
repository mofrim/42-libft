/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:22:09 by fmaurer           #+#    #+#             */
/*   Updated: 2025/01/13 14:04:59 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocate nmemb memsize'd blocks.
 * Example: ft_calloc(12, sizeof(int)); */
void	*ft_calloc(size_t nmemb, size_t memsize)
{
	void	*mem;

	mem = malloc(nmemb * memsize);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * memsize);
	return (mem);
}
