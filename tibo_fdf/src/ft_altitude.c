/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_altitude.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:26:06 by tlamart           #+#    #+#             */
/*   Updated: 2019/04/26 18:52:12 by erlazo           ###   ########.fr       */
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
