/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:35:53 by tlamart           #+#    #+#             */
/*   Updated: 2019/06/26 14:49:29 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_zoom_in(t_fdf *mlx)
{
	mlx->map_scale += 1;
	return (ft_redraw(mlx));
}

int		ft_zoom_out(t_fdf *mlx)
{
	if (mlx->map_scale - 1)
	{
		mlx->map_scale -= 1;
		return (ft_redraw(mlx));
	}
	return (0);
}
