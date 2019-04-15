
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
	t_point	start;
	t_point	end;
	
	if (ac != 5)
		return (0);
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	fdf->size = 10;
	fdf->mlx = mlx_init();
	fdf->wind = mlx_new_window(fdf->mlx, 700, 700, "testing");
	start.x = ft_atoi(av[1]);
	start.y = ft_atoi(av[2]);
	end.x = ft_atoi(av[3]);
	end.y = ft_atoi(av[4]);
	draw_line(&start, &end, fdf);

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
