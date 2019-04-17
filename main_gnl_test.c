

#include "fdf.h"




int		main(int ac, char **av)
{
	char	*l;
	char	*s;
	int		fd;

	s = ft_strnew(1);;
	if (ac != 2)
		return (0);
	
	fd = open(av[1], O_RDONLY);
	while (gnl(&l, &s, 1, fd) > 0)
	{
		printf("%s\n", l);
	}
	close(fd);
	return (0);
}
