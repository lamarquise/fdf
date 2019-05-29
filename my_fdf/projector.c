

#include "fdf.h"


	// need to work on border, it stays the same size for some reason...

	// for now it won't be very sofisticated, just for testing other components

// TOTALLY forgot, multiplied all by 2...

	// fixed to handle the grid relative to origin...

	// this 1st itteration might be too square...

/*
void		pos_to_pixel(t_f3d p, t_fdf *fdf)
{
	
}
*/

t_p2d		**project(t_f3d **tab, t_fdf *fdf)	// need the second part?
{
	int		x;
	int		y;
	int		len;
	t_p2d	**ret;
//	int		dep;
//	float	test;

	// (-n/ze * xe, ye, -n)		// we dont care about z axis... set -n = -1 and have 1/ze


//	printf("win len %i, len %i, win lon %i, lon %i\n", fdf->win_len, fdf->len, fdf->win_lon, fdf->lon);

//	dep = ((fdf->high + fdf->low) / 2 > 0 ? (fdf->high + fdf->low) / 2 : 1);
	len = (fdf->win_len / (fdf->len + 1) < fdf->win_lon / (fdf->lon + 1)) ? fdf->win_len / (fdf->len + 1) : fdf->win_lon / (fdf->lon + 1);
	
//	printf("len %i\n", len);

	if (!(ret = (t_p2d **)malloc(sizeof(t_p2d *) * fdf->lon)))
		return (0);
	y = 0;
	while (y < fdf->lon)
	{
		x = 0;
		if (!(ret[y] = (t_p2d *)malloc(sizeof(t_p2d) * fdf->len)))
			return (0);
		while (x < fdf->len)
		{														// can this be done with an int ???
			//how to translate pos to pixel...




//			ret[y][x].x = (fdf->win_len / 2) + ((((tab[y][x].x * dep) / tab[y][x].z) + 1) * len / 2);
			ret[y][x].x = (fdf->win_len / 2) + (((tab[y][x].x / tab[y][x].z) + 1) * len / 2);
//			printf("x: %f\n", test);
//			ret[y][x].y = (fdf->win_lon / 2) + ((((tab[y][x].y * dep) / tab[y][x].z) + 1) * len / 2);	// this is where we multiply by z ???
			ret[y][x].y = (fdf->win_lon / 2) + (((tab[y][x].y / tab[y][x].z) + 1) * len / 2);
			++x;
		}
		++y;
	}
	return (ret);
}
