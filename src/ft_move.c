/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:15:33 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 20:18:42 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		ft_up(t_fdf *mlx)
{
	mlx->omy -= 5 * mlx->win_width * mlx->map_scale;
	mlx->map_origin -= 5 * mlx->win_width * mlx->map_scale;
	return (ft_redraw(mlx));
}

int		ft_down(t_fdf *mlx)
{
	mlx->omy += 5 * mlx->win_width * mlx->map_scale;
	mlx->map_origin += 5 * mlx->win_width * mlx->map_scale;
	return (ft_redraw(mlx));
}

int		ft_right(t_fdf *mlx)
{
	mlx->omx += 5 * mlx->map_scale;
	mlx->map_origin += 5 * mlx->map_scale;
	return (ft_redraw(mlx));
}

int		ft_left(t_fdf *mlx)
{
	mlx->omx -= 5 * mlx->map_scale;
	mlx->map_origin -= 5 * mlx->map_scale;
	return (ft_redraw(mlx));
}
