/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:44:21 by erlazo            #+#    #+#             */
/*   Updated: 2019/04/16 14:17:08 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H


# include <stdio.h>


# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "gnl.h"


typedef struct	s_line
{
	char			**tab;
	int				size;
	struct s_line	*next;
}				t_line;

typedef struct	s_pixel				// basically as fast to send values as it is to send pointer...
{
	int		x;
	int		y;
	int		color;
}				t_pixel;

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

typedef struct	s_grid
{
	t_p2p	**tab;
	int		len;
	int		lon;
}				t_grid;

typedef struct	s_fdf
{
	void	*mlx;
	void	*wind;
	int		size;
	
}				t_fdf;

int		draw_line(t_p2d s, t_p2d e, t_fdf *fdf);			// although sending a pointer is cheaper than sending a struct cuz it has to dup the struct on the other side right?
void	swap_void(void **c1, void **c2);
int		print_grid(t_p2d **tab, t_fdf *fdf);
int		line_list_count(t_line *lst);
int		str_count(char **tab);
t_p3d	**parse_map(int fd);
int     print_3_grid(t_p3d **tab, t_fdf *fdf);


#endif




