

#include "fdf.h"

	// sets all values relative to origin in the middle... should we be using a copy???

int		originate_map(t_f3d **tab, t_fdf *fdf)
{
	int		x;
	int		y;
	int		zed;
	
	y = 0;
	zed = (fdf->low > 0 ? -fdf->low : fdf->low) + 1;
	while (y < fdf->lon)
	{
		x = 0;
		while (x < fdf->len)
		{
			tab[y][x].x = tab[y][x].x * 2 - fdf->len;		//cuz all * 2 so only ints...
			tab[y][x].y = tab[y][x].y * 2 - fdf->lon;		// z is already relative to 0
			
			// will come up with a better solition...
			tab[y][x].z += zed;
//			tab[y][x].z = fdf->high + fdf->low + 1;
			++x;
		}								// could do -1 or somthing tho if decide later...
		++y;
	}
	return (1);
}
