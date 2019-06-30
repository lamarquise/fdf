/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:44:33 by erlazo            #+#    #+#             */
/*   Updated: 2019/06/30 14:40:00 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



		// Use the Xialin Wu methode later...


int		draw_line(t_p2d s, t_p2d e, t_fdf *fdf)			// clearly this shit needs to be shorter or many funcs but for now it work... also manage colors?
{																	// call another func to manage colors ???
	float	grad;
	int		dy;
	int		dx;
	int		offset;
	int		threshold; //* 2 so is an int so also ++2 when increment...
	int		adj;
	int		delta;
	int		thresholdinc;
	t_p2d	p;
	t_p2d	*start;										// seriously clean this shit up at some point, it's gross
	t_p2d	*end;

	adj = 1;
	p.x = 0;
	p.y = 0;
	offset = 0;

	start = (t_p2d *)malloc(sizeof(t_p2d));
	end = (t_p2d *)malloc(sizeof(t_p2d));

	start->x = s.x;
	start->y = s.y;
	end->x = e.x;
	end->y = e.y;
	if (end->x < start->x && end->y < start->y)				// this could be a problem....
		swap_void((void *)&start, (void *)&end);
	dx = end->x - start->x;
	dy = end->y - start->y;
	if (dx == 0)
	{
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
		if (end->x < start->x)
			swap_void((void *)&start, (void *)&end);
		while (p.x <= end->x - start->x)
		{
			mlx_pixel_put(fdf->mlx, fdf->wind, start->x + p.x, start->y, 0xFFFFFF);
			++p.x;
		}
		return (1);
	}
	grad = (float)dy / (float)dx;
	if (grad <= 1 && grad >= -1)	// btw 45 and -45 deg x changes by 1 everytime
	{
		if (end->x < start->x)
			swap_void((void *)&start, (void *)&end);
		if (grad < 0)
			adj = -1;
		delta = abs(dy) * 2;
		threshold = abs(dx);
		thresholdinc = abs(dx) * 2;		// leave this and delta so as less math!!!
		while (p.x <= end->x - start->x)
		{
			mlx_pixel_put(fdf->mlx, fdf->wind, start->x + p.x, start->y + p.y, 0xFFFFFF);
			offset += delta;
			if (offset >= threshold)
			{
				p.y += adj;
				threshold += thresholdinc;
			}
			++p.x;
		}
		return (1);
	}
	else // greater than 45 or smaller than -45 deg, y changes by 1 everytime
	{
		if (end->y < start->y)
			swap_void((void *)&start, (void *)&end);
		if (grad < 0)
			adj = -1;
		delta = abs(dx) * 2;
		threshold = abs(dy);
		thresholdinc = abs(dy) * 2;
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
