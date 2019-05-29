

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf	*fdf;
	t_f3d	**tab;
	int		fd;

	if (ac != 4)
		return (0);
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	fdf->win_len = ft_atoi(av[2]);
	fdf->win_lon = ft_atoi(av[3]);
	fdf->mlx = mlx_init();
	fdf->wind = mlx_new_window(fdf->mlx, fdf->win_len, fdf->win_lon, "testing");
	
	fd = open(av[1], O_RDONLY);

//	print_grid(project(parse_map(fd, fdf), fdf), fdf);		//using tmp for now...
	
	tab = parse_map(fd, fdf);

	originate_map(tab, fdf);

	// something that generates 3x3 transformations matrices

	if (!apply_t(tab, push_r(), fdf))
		return (0);
	
	//change the map with commands???		//we need a func betw parser and proj for rots...

//	printf("Coor: x %i, y %i z %i\n", tab[0][0].x, tab[0][0].y, tab[0][0].z);

	
	print_grid(project(tab, fdf), fdf);
	mlx_loop(fdf->mlx);
	close(fd);
	return (0);
}
