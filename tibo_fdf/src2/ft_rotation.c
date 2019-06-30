/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:23:02 by erlazo            #+#    #+#             */
/*   Updated: 2019/06/30 15:35:04 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define PI 3.14159/180

int		ft_rot_z_left(t_fdf *mlx)
{
	mlx->r_z -= 5;
	return (ft_redraw(mlx));
}

int     ft_rot_z_right(t_fdf *mlx)
{
	mlx->r_z += 5;
	return (ft_redraw(mlx));
}

int     ft_rot_x_left(t_fdf *mlx)
{
	mlx->r_x -= 5;
	return (ft_redraw(mlx));
}

int     ft_rot_x_right(t_fdf *mlx)
{
	mlx->r_x += 5;
	return (ft_redraw(mlx));
}
int     ft_rot_y_left(t_fdf *mlx)
{
	mlx->r_y -= 5;
	return (ft_redraw(mlx));
}

int     ft_rot_y_right(t_fdf *mlx)
{
	mlx->r_y += 5;
	return (ft_redraw(mlx));
}

void	ft_rotcoord(t_fdf *mlx, t_coord *c)
{
	float	tab[6];								// this will undetedly be imprecise, that can be fixed later tho
	float	mat[9];
	t_coord	tmp;

	tab[0] = cos(mlx->r_x * PI);
	tab[1] = sin(mlx->r_x * PI);
	tab[2] = cos(mlx->r_y * PI);
	tab[3] = sin(mlx->r_y * PI);
	tab[4] = cos(mlx->r_z * PI);
	tab[5] = sin(mlx->r_z * PI);

	mat[0] = tab[2] * tab[4];
	mat[1] = -(tab[2]) * tab[5];
	mat[2] = tab[3];
	mat[3] = tab[1] * tab[3] * tab[4] + tab[0] * tab[5];
	mat[4] = -(tab[1] * tab[3] * tab[5]) + tab[0] * tab[4];
	mat[5] = -(tab[1] * tab[2]);
	mat[6] = -(tab[0] * tab[3] * tab[4]) + tab[1] * tab[5];
	mat[7] = tab[0] * tab[3] * tab[5] + tab[1] * tab[4];
	mat[8] = tab[0] * tab[2];

	tmp.x = mat[0] * c->x + mat[1] * c->y + mat[2] * c->z;
	tmp.y = mat[3] * c->x + mat[4] * c->y + mat[5] * c->z;
	tmp.z = mat[6] * c->x + mat[7] * c->y + mat[8] * c->z;

	c->x = tmp.x;
	c->y = tmp.y;
	c->z = tmp.z;
}

void	ft_rotmap(t_fdf *mlx, t_list *map)
{
	int		i;
	t_coord	*coord_tab;

	while (map)
	{
		i = 0;
		coord_tab = (t_coord*)map->content;
		while (i < map->content_size)
		{
			ft_rotcoord(mlx, &coord_tab[i]);
			++i;
		}
		map = map->next;
	}
}





