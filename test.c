/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:40:18 by fmaurer           #+#    #+#             */
/*   Updated: 2024/11/18 18:41:17 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*str;
	char	*dst;
	int		cnt;

	str = "This is is so depressing.";
	dst = ft_strcpy(str);
	ft_printf("dst: %s\n", dst);
	free(dst);
	return (0);
}
