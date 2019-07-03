/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 08:20:54 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 08:25:24 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_drawtool(t_fdf *mlx, t_list *list3d)
{
	t_list	*copy;

	mlx->img_data[mlx->map_origin] = mlx->color + 100;
	mlx->img_data[mlx->map_origin + 1] = mlx->color + 100;
	mlx->img_data[mlx->map_origin - 1] = mlx->color + 100;
	mlx->img_data[mlx->map_origin + mlx->win_width] = mlx->color + 100;
	mlx->img_data[mlx->map_origin - mlx->win_width] = mlx->color + 100;
	copy = ft_copylist(list3d);
	ft_centermap(mlx, copy);
	ft_rotmap(mlx, copy);
	ft_scale_coord(mlx, copy);
	return (copy);
}
