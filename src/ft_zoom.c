/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:35:53 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 20:31:17 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_zoom_in(t_fdf *mlx)
{
	if (mlx->map_scale >= 1)
		mlx->map_scale += 1;
	else
		mlx->map_scale *= 2;
	return (ft_redraw(mlx));
}

int		ft_zoom_out(t_fdf *mlx)
{
	if (mlx->map_scale - 1 > 0)
	{
		mlx->map_scale -= 1;
		mlx->map_scale = (int)mlx->map_scale;
		return (ft_redraw(mlx));
	}
	else
	{
		mlx->map_scale /= 2;
		return (ft_redraw(mlx));
	}
	return (0);
}
