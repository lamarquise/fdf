/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:35:40 by tlamart           #+#    #+#             */
/*   Updated: 2019/04/26 18:46:08 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ft_getcoord_iso(t_coord a, t_coord b, t_coord *a2d, t_coord *b2d)
{
	a2d->x = (a.x - a.y) * cos(0.523599);
	a2d->y = -a.z + (a.x + a.y) * sin(0.523599);
	b2d->x = (b.x - b.y) * cos(0.523599);
	b2d->y = -b.z + (b.x + b.y) * sin(0.523599);
}

int		ft_projection_iso(t_fdf *mlx)
{
	mlx->projection = &ft_getcoord_iso;
	return (ft_redraw(mlx));
}

int		ft_projection_par(t_fdf *mlx)
{
	mlx->projection = &ft_getcoord_par;
	return (ft_redraw(mlx));
}

int		ft_change_projection(t_fdf *mlx)
{
	if (mlx->projection == &ft_getcoord_par)
		return (ft_projection_iso(mlx));
	else
		return (ft_projection_par(mlx));
}
