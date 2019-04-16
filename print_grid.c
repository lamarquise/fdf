/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:11:15 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/16 12:07:57 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


/*		// shit can't actually test this...

int		print_3_grid(t_p3d **tab, t_fdf *fdf)			// only works with rectangles
{
	int		x;
	int		y;
	int		a;
	int		b

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x + 1])
		{
			draw_line(tab[y][x], tab[y][x + 1], fdf);
			++x;
		}
		++y;
	}
	a = 0;
	while (a < x)
	{
		b = 0;
		while (b < y)
		{
			draw_line(tab[b][a], tab[b + 1][a], fdf);
			++b;
		}
		++a;
	}
	return (0);
}

*/

int		print_grid(t_p2d **tab, t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 9) // 9 ???
		{
			draw_line(tab[y][x], tab[y][x + 1], fdf);
			++x;
		}
		++y;
	}
	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 9)
		{
			draw_line(tab[y][x], tab[y + 1][x], fdf);
			++y;
		}
		++x;
	}
	return (0);
}
