#include "libft/libft.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	char	*str = "b";
	char	*dst;
	int		cnt;

	dst = ft_strcpy(str);
	ft_printf("dst: %s\n", dst);
	free(dst);
	return (0);
}
