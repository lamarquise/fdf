/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:44:21 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/15 18:50:07 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H


# include <stdio.h>


# include <math.h>
# include "mlx.h"
# include "libft.h"

typedef struct	s_p2d
{
	int		x;
	int		y;
}				t_p2d;

typedef struct	s_p3d				// floats??? how to use only ints in 2D and 3D of whole thing... ????
{
	int		x;
	int		y;
	int		z;
}				t_p3d;




typedef struct	s_fdf
{
	void	*mlx;
	void	*wind;
	int		size;
	
}				t_fdf;

int		draw_line(t_p2d s, t_p2d e, t_fdf *fdf);			// although sending a pointer is cheaper than sending a struct cuz it has to dup the struct on the other side right?
void	swap_void(void **c1, void **c2);
int		print_grid(t_p2d **tab, t_fdf *fdf);

#endif
