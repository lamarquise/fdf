/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 08:20:54 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 18:47:29 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_drawtool(t_fdf *mlx, t_list *list3d)
{
	t_list	*copy;

	if (mlx->map_origin - mlx->win_width > 0
	&& mlx->map_origin + mlx->win_width < mlx->last_pix)
	{
		mlx->img_data[mlx->map_origin] = 0xffffff;
		mlx->img_data[mlx->map_origin + 1] = 0xffffff;
		mlx->img_data[mlx->map_origin - 1] = 0xffffff;
		mlx->img_data[mlx->map_origin + mlx->win_width] = 0xffffff;
		mlx->img_data[mlx->map_origin - mlx->win_width] = 0xffffff;
	}
	if (!(copy = ft_copylist(list3d)))
	{
		ft_putstr_fd("copying failed\n", 2);
		ft_quitfdf(mlx);
	}
	ft_centermap(mlx, copy);
	ft_rotmap(mlx, copy);
	ft_scale_coord(mlx, copy);
	return (copy);
}
