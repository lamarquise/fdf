/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:44:21 by erlazo            #+#    #+#             */
/*   Updated: 2019/05/28 18:42:03 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

//# include "get_next_line.h"
# include <stdio.h>

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"


# define PI 3.14


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

typedef struct	s_f3d				// for the transform math cuz it complicated...
{
	float	x;
	float	y;
	float	z;
}				t_f3d;

typedef struct	s_p4d
{
	int		x;
	int		y;
	int		z;
	int		w;
}				t_p4d;

typedef struct	s_hom			//homogeneous matrix
{
	t_p4d	a;				// nomenclature is clear ???
	t_p4d	b;
	t_p4d	c;
	t_p4d	d;
}				t_hom;

typedef struct	s_grid
{
	t_p2d	**tab;
	int		len;
	int		lon;
}				t_grid;

typedef struct	s_fdf
{
	void	*mlx;
	void	*wind;
//	int		size;				// to be removed eventually...
	int		len;		// x max length
	int		lon;		// y max length
	int		win_len;
	int		win_lon;
	int		low;
	int		high;
}				t_fdf;

int		draw_line(t_p2d s, t_p2d e, t_fdf *fdf);			// although sending a pointer is cheaper than sending a struct cuz it has to dup the struct on the other side right?
void	swap_void(void **c1, void **c2);
int		print_grid(t_p2d **tab, t_fdf *fdf);
int		line_list_count(t_line *lst);
int		str_count(char **tab);
t_f3d	**parse_map(int fd, t_fdf *fdf);
t_p2d	**project(t_f3d **tab, t_fdf *fdf);
int		originate_map(t_f3d **tab, t_fdf *fdf);
int		apply_t(t_f3d **tab, t_f3d *trans, t_fdf *fdf);


/*	Functions that produce the Transformation Tables */

t_f3d	*rot_90_r();
t_f3d	*rot_90_l();

t_f3d	*push_r();		// no idea if math is cor....

#endif




