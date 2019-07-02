/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:02:03 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/01 15:47:51 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_positive_diff_dx_greater_than_dy(t_fdf *mlx, t_coord a, t_coord b, t_line err)
{
//	ft_putstr("00\n");
	while (a.x <= b.x)
	{
		mlx->img_data[mlx->map_origin + a.y * mlx->win_width + a.x] = mlx->color;					// these might be the things that have to change 
		a.x += 1;																					// for rotation to be around center...
		err.sign += err.x;
		if (err.sign < 0)
		{
			a.y += 1;
			err.sign += err.y;
		}
	}
}

void	ft_positive_diff_dy_greater_than_dx(t_fdf *mlx, t_coord a, t_coord b, t_line err)
{
//	ft_putstr("11\n");
	while (a.y <= b.y)
	{
		mlx->img_data[mlx->map_origin + a.y * mlx->win_width + a.x] = mlx->color;
		a.y += 1;
		err.sign += err.x;
		if (err.sign < 0)
		{
			a.x += 1;
			err.sign += err.y;
		}
	}
}

void	ft_negative_diff_dx_greater_than_dy(t_fdf *mlx, t_coord a, t_coord b, t_line err)
{
//	ft_putstr("22\n");
	while (a.x <= b.x)
	{
		mlx->img_data[mlx->map_origin + a.y * mlx->win_width + a.x] = mlx->color;
		a.x += 1;
		err.sign -= err.x;
		if (err.sign < 0)
		{
			a.y -= 1;
			err.sign += err.y;
		}
	}
}

void	ft_negative_diff_dy_greater_than_dx(t_fdf *mlx, t_coord a, t_coord b, t_line err)
{
//	ft_putstr("33\n");
	printf("a.x = %d, a.y = %d\nb.x = %d, b.y = %d\n", a.x, a.y, b.x, b.y);
	printf("err.x = %d err.y = %d err.sign = %d\n", err.x, err.y, err.sign);
	while (a.y >= b.y)
	{
		mlx->img_data[mlx->map_origin + a.y * mlx->win_width + a.x] = mlx->color;
		a.y -= 1;
		err.sign -= err.x;
		if (err.sign > 0)
		{
			a.x += 1;
			err.sign += err.y;
		}
	}
}
