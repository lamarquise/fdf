
#include "fdf.h"


void    print_square(t_fdf *fdf);


int		print_key(int key, void *ptr)
{
//	key = 0;
	(void)ptr;
//	ft_putchar('X');
	ft_putnbr(key);
	write(1, "\n", 1);
	return (0);
}

int		zoom(int key, t_fdf *fdf)
{
	int		i;

	ft_putstr("test zoom\n");
	i = fdf->size;
	ft_putnbr(key);
	write(1, "\n", 1);
	if (i > 0)
	{
		ft_putstr("test\n");
		if (i > 1 && key == 0)
			i--;
		else if (key == 1)
			i++;
	}
	fdf->size = i;
	ft_putstr("size: ");
	ft_putnbr(fdf->size);
	write(1, "\n", 1);
	print_square(fdf);				// ok so i can print an square, but can't delete it...
	return (0);
}

void	print_square(t_fdf *fdf)
{
	int		start;

	start = 0;
	while (start < fdf->size * 2)
	{
		mlx_pixel_put(fdf->mlx, fdf->wind, 250 - fdf->size + start, 250 + fdf->size, 0xFFFFFF);
		mlx_pixel_put(fdf->mlx, fdf->wind, 250 - fdf->size + start, 250 - fdf->size, 0xFFFFFF);
		mlx_pixel_put(fdf->mlx, fdf->wind, 250 - fdf->size, 250 - fdf->size + start, 0xFFFFFF);
		mlx_pixel_put(fdf->mlx, fdf->wind, 250 + fdf->size, 250 - fdf->size + start, 0xFFFFFF);
		++start;
	}
}



int		main(int ac, char **av)
{
	t_fdf	*fdf;
	t_p2d	start;
	t_p2d	end;
	t_p2d	**tab;
	int		x;
	int		y;
	int		fd;
	
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	fdf->size = 10;
	fdf->mlx = mlx_init();
	fdf->wind = mlx_new_window(fdf->mlx, 1000, 1000, "testing");
	fdf->win_len = 1000;
	fdf->win_lon = 1000;

	if (ac == 1)
	{
		if (!(tab = (t_p2d **)malloc(sizeof(t_p2d *) * 10)))
			return (0);
		y = 0;
		while (y < 10)
		{
			if (!(tab[y] = (t_p2d *)malloc(sizeof(t_p2d) * 10)))
				return (0);
			x = 0;
			while (x < 10)
			{
				tab[y][x].x = 20 * (x - y) + 250;
				tab[y][x].y = 20 * y + 100;
				++x;
			}
			++y;
		}
		print_grid(tab, fdf);
	}
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		print_grid(project(parse_map(fd, fdf), fdf), fdf);
		close(fd);
	}
	else if (ac == 7)
	{
		start.x = ft_atoi(av[1]);
		start.y = ft_atoi(av[2]);
		end.x = ft_atoi(av[3]);
		end.y = ft_atoi(av[4]);
		draw_line(start, end, fdf);	
		start.x = ft_atoi(av[5]);
		start.y = ft_atoi(av[6]);
		draw_line(start, end, fdf);
	}	


//	mlx_key_hook(fdf->wind, zoom, fdf);
	
//	mlx_mouse_hook(wind, zoom, (void *)&size);
//	ft_putstr("main test\n");
//	print_square(fdf);

//	mlx_mouse_hook(wind, print_key, (void *)0);
//	mlx_key_hook(wind, print_key, (void *)0);
//	mlx_pixel_put(mlx, wind, 
	mlx_loop(fdf->mlx);
	return (0);
}
