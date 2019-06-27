/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:11:15 by erlazo            #+#    #+#             */
/*   Updated: 2019/06/27 12:08:02 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


	// to handle non rectangular grids would need a table of structures each with line len. not a table of tables...

int		print_grid(t_p2d **tab, t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->lon)
	{
		x = 0;
		while (x < fdf->len - 1) // 9 ???
		{
			draw_line(tab[y][x], tab[y][x + 1], fdf);
			++x;
		}
		++y;
	}
	x = 0;
	while (x < fdf->len)
	{
		y = 0;
		while (y < fdf->lon - 1)
		{
			draw_line(tab[y][x], tab[y + 1][x], fdf);
			++y;
		}
		++x;
	}
	return (0);
}
