/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:40:18 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 01:02:25 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*str;
	char	*dst;
	int		cnt;
	int		fd;

	str = "This is is so depressing.";
	dst = ft_strcpy(str);
	ft_printf("dst: %s\n", dst);
	fd = open("./bla.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR | S_IRUSR);
	if (fd < -1)
		return (2);
	ft_fprintf(fd, "does this work ? av[0] = %s", av[0]);
	close(fd);
	free(dst);
	return (0);
}
