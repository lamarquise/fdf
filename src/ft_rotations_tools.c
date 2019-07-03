/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:56:35 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 08:12:31 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_rot_x_left(t_fdf *mlx)
{
	mlx->r_x -= 5;
	return (ft_redraw(mlx));
}

int		ft_rot_x_right(t_fdf *mlx)
{
	mlx->r_x += 5;
	return (ft_redraw(mlx));
}

int		ft_rot_y_left(t_fdf *mlx)
{
	mlx->r_y -= 5;
	return (ft_redraw(mlx));
}

int		ft_rot_y_right(t_fdf *mlx)
{
	mlx->r_y += 5;
	return (ft_redraw(mlx));
}
