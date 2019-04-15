

#include "fdf.h"



int		draw_line(t_point *start, t_point *end, t_fdf *fdf)
{
	float	grad;			//floats???
	int		dy;
	int		dx;
	int		offset;
	int		threshold; //* 2 so is an int so also ++2 when increment...
	int		adj;
	int		delta;
	int		thresholdinc;
	t_point	p;

	adj = 1;
	p.x = 0;
	p.y = 0;
	offset = 0;


	if (end->x < start->x && end->y < start->y)
		swap_void((void *)&start, (void *)&end);
	
	printf("startx,y: %i, %i, endx,y: %i, %i\n", start->x, start->y, end->x, end->y);

	dx = end->x - start->x;			// will have to manage fliping start and end depending
	dy = end->y - start->y;		//on where they are relative to each other... ignore for now
	if (dx == 0)
	{
		printf("x const no change\n");
		if (end->y < start->y)
			swap_void((void *)&start, (void *)&end);
		while (p.y <= end->y - start->y)
		{
			mlx_pixel_put(fdf->mlx, fdf->wind, start->x, start->y + p.y, 0xFFFFFF);
			++p.y;
		}
		return (1);
	}
	else if (dy == 0)
	{
		printf("y const no change\n");
		if (end->x < start->x)
			swap_void((void *)&start, (void *)&end);
		while (p.x <= end->x - start->x)
		{
			mlx_pixel_put(fdf->mlx, fdf->wind, start->x + p.x, start->y, 0xFFFFFF);
			++p.x;
		}
		return (1);
	}
	grad = dy / dx;
	if (grad <= 1 && grad >= -1)	// btw 45 and -45 deg x changes by 1 everytime
	{
		printf("x const change\n");
		if (end->x < start->x)	// swap is necessary but if reset dx and dy fuckes everything 
		{						// up, not sure why...
			printf("swap test\n");
			swap_void((void *)&start, (void *)&end);
//			dx = end->x - start->x;
//			dy = end->y - start->y;
		}
		printf("startx,y: %i, %i, endx,y: %i, %i\n", start->x, start->y, end->x, end->y);
		if (grad < 0)
			adj = -1;

		printf("adj:%i, dy:%i, dx:%i\n", adj, dy, dx);

		delta = ABS(dy) * 2;
		threshold = ABS(dx);
		thresholdinc = ABS(dx) * 2;		// leave this and delta so as less math!!!
		while (p.x <= end->x - start->x)
		{
			printf("off: %i, Thresh: %i\n", offset, threshold);
			mlx_pixel_put(fdf->mlx, fdf->wind, start->x + p.x, start->y + p.y, 0xFFFFFF);
			offset += delta;
			if (offset >= threshold)
			{
				printf("x: %i\n", p.x);
				p.y += adj;
				threshold += thresholdinc;
			}
			++p.x;
		}
		return (1);
	}
	else if (grad > 1 && grad < -1)	// greater than 45 or smaller than -45 deg
	{								// y changes by 1 everytime
		printf("y const change\n");
		if (end->y < start->y)
		{
			swap_void((void *)&start, (void *)&end);
			dx = end->x - start->x;
			dy = end->y - start->y;
		}
		printf("startx,y: %i, %i, endx,y: %i, %i\n", start->x, start->y, end->x, end->y);
		if (grad < 0)
			adj = -1;
		delta = ABS(dx) * 2;
		threshold = ABS(dy);
		thresholdinc = ABS(dy) * 2;
		while (p.y <= end->y - start->y)
		{
			mlx_pixel_put(fdf->mlx, fdf->wind, start->x + p.x, start->y + p.y, 0xFFFFFF);
			offset += delta;
			if (offset >= threshold)
			{
				p.x += adj;
				threshold += thresholdinc;
			}
			++p.y;
		}
		return (1);
	}
	return (0);
}
