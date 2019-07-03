/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:15:33 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/01 17:22:00 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		ft_up(t_fdf *mlx)
{
	mlx->omy -= 5 * mlx->win_width;
	mlx->map_origin -= 5 * mlx->win_width;
	return (ft_redraw(mlx));
}

int		ft_down(t_fdf *mlx)
{
	mlx->omy += 5 * mlx->win_width;
	mlx->map_origin += 5 * mlx->win_width;
	return (ft_redraw(mlx));
}

int		ft_right(t_fdf *mlx)
{
	mlx->omx += 5;
	mlx->map_origin += 5;
	return (ft_redraw(mlx));
}

int		ft_left(t_fdf *mlx)
{
	mlx->omx -= 5;
	mlx->map_origin -= 5;
	return (ft_redraw(mlx));
}
