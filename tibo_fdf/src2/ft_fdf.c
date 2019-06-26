/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 00:56:10 by tlamart           #+#    #+#             */
/*   Updated: 2019/06/26 12:06:49 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void		ft_clear_mlx(t_fdf *mlx)
{
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->ptr, mlx->img_ptr);
	if (mlx->win_ptr)
	{
		mlx_clear_window(mlx->ptr, mlx->win_ptr);
		mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	}
}

int			ft_quitfdf(t_fdf *mlx)
{
	ft_lstdel(mlx->list_coord, ft_lstdel_cnt);
	ft_clear_mlx(mlx);
	exit(0);
}


static void	ft_abort(t_fdf *mlx, t_list **list, char *err_msg)
{
	ft_clear_mlx(mlx);
	ft_lstdel(list, ft_lstdel_cnt);
	ft_putstr_fd(err_msg, 2);
}

void		ft_fdf(t_list **list3d)
{
	t_fdf	mlx;
	int		status;

	if ((status = ft_initfdf(*list3d, &mlx)))
		return (ft_abort(&mlx, list3d, "mlx_init() failed\n"));
	ft_draw(&mlx, *list3d);
	mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx.list_coord = list3d;
//	mlx_do_key_autorepeaton(mlx.ptr);
	mlx_key_hook(mlx.win_ptr, &ft_keyhook, &mlx);
	mlx_loop(mlx.ptr);														// possibly add some things here that Cesar suggested...
//	mlx_loop_hook(mlx.ptr, mlx_do_key_autorepeaton, mlx.ptr);
}
