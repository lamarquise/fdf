

#include "fdf.h"

	// for now it won't be very sofisticated, just for testing other components

t_p2d		**project(t_p3d **tab, t_fdf *fdf)	// need the second part?
{
	int		x;
	int		y;
	t_p2d	**ret;

	if (!(ret = (t_p2d **)malloc(sizeof(t_p2d *) * fdf->lon)))
		return (0);
	y = 0;
	while (y < fdf->lon)
	{
		x = 0;
		if (!(ret[y] = (t_p2d *)malloc(sizeof(t_p2d) * fdf->len)))
			return (0);
		while (x < fdf->len)
		{
			ret[y][x].x = (tab[y][x].x + 1) * (fdf->win_len / (fdf->len + 2));
			ret[y][x].y = (tab[y][x].y + 1) * (fdf->win_lon / (fdf->lon + 2));		// this is where we multiply by z or whatever...
			++x;
		}
		++y;
	}
	return (ret);
}
