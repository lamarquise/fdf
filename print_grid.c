/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:11:15 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/15 18:37:22 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
