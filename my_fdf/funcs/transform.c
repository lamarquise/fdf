

#include "fdf.h"

	// i am imagining trans as beign a table of 3 t_p3d's (the t_p3ds are columns???);

	// yes each of the 3 points in the table is a column (since they each have x, y, and z

int		apply_t(t_f3d **tab, t_f3d *t, t_fdf *fdf)
{
	int		x;
	int		y;

//	printf("Coor: x %i, y %i z %i\n", tab[0][0].x, tab[0][0].y, tab[0][0].z);
	
	y = 0;
	while (y < fdf->lon)
	{
		x = 0;
		while (x < fdf->len)
		{
			// i really hope this is correct...
			tab[y][x].x = tab[y][x].x * t[0].x + tab[y][x].y * t[1].x + tab[y][x].z * t[2].x;
			tab[y][x].y = tab[y][x].x * t[0].y + tab[y][x].y * t[1].y + tab[y][x].z * t[2].y;
			tab[y][x].z = tab[y][x].x * t[0].z + tab[y][x].y * t[1].z + tab[y][x].z * t[2].z;
			++x;
		}
		++y;
	}
//	printf("Coor: x %i, y %i z %i\n", tab[0][0].x, tab[0][0].y, tab[0][0].z);
	return (1);
}
