#include "libft/libft.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	ft_printf("%042d, hello world\n", 42);
	ft_printf("%s\n", ft_strdup("ataat"));

	char	*line;

	int fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
		ft_printf("line: %s", line);

	return (0);
}
