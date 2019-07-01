/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_altitude.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:26:06 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/01 17:36:02 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		ft_increase_altitude(t_fdf *mlx)
{
	mlx->map_altitude += 1;
	return (ft_redraw(mlx));
}

int		ft_decrease_altitude(t_fdf *mlx)
{
	mlx->map_altitude -= 1;
	return (ft_redraw(mlx));
}

int		ft_raise_sealevel(t_fdf *mlx)
{
	mlx->sealevel += 1;
	return (ft_redraw(mlx));
}

int		ft_lower_sealevel(t_fdf *mlx)
{
		mlx->sealevel -= 1;
		return (ft_redraw(mlx));
}
