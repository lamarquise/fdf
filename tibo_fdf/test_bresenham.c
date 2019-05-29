/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:46:11 by tlamart           #+#    #+#             */
/*   Updated: 2019/04/25 14:36:33 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	ft_init_mlx(t_fdf *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->ptr, 500, 500, "bresenham");
	mlx->img_ptr = mlx_new_image(mlx->ptr, 500, 500);
	mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->s_l,\
	&mlx->endian);
	mlx->color = 0x00FF6600;
	mlx->map_origin = 0;
	mlx->win_width = 500;
	mlx->win_height = 500;
}

void    ft_drawline(t_fdf *mlx, t_coord a, t_coord b)
{
	if (b.x - a.x < 0)
		return (ft_drawline(mlx, b, a));
	ft_bresenham(mlx, a, b);
}

int		main(void)
{
	t_coord		a;
	t_coord		b;
	t_fdf		mlx;

	ft_init_mlx(&mlx);
	a.x = 250;
	a.y = 250;
	b.x = 250;
	b.y = 100;
	while (b.x < 400)
	{
		ft_drawline(&mlx, a, b);
		b.x += 5;
	}
	while (b.y < 250)
	{
		ft_drawline(&mlx, a, b);
		b.y += 7;
	}
	while (b.y < 400)
	{
		ft_drawline(&mlx, a, b);
		b.y += 9;
	}
	while (b.x > 250)
	{
		ft_drawline(&mlx, a, b);
		b.x -= 11;
	}
	while (b.x > 100)
	{
		ft_drawline(&mlx, a, b);
		b.x -= 13;
	}
	while (b.y > 250)
	{
		ft_drawline(&mlx, a, b);
		b.y -= 15;
	}
	while (b.y > 100)
	{
		ft_drawline(&mlx, a, b);
		b.y -= 17;
	}
	while (b.x < 250)
	{
		ft_drawline(&mlx, a, b);
		b.x += 19;
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.ptr);
}
