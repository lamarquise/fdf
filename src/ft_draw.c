/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:44:02 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 08:27:07 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_getcoord_par(t_coord a, t_coord b, t_coord *a2d, t_coord *b2d)
{
	a2d->x = a.x + a.z / 2;
	a2d->y = a.y - a.z / 2;
	b2d->x = b.x + b.z / 2;
	b2d->y = b.y - b.z / 2;
}

void	ft_scale_coord(t_fdf *mlx, t_list *a)
{
	t_coord *p;
	size_t	i;

	while (a)
	{
		i = 0;
		p = (t_coord*)a->content;
		while (i < a->content_size)
		{
			p[i].x *= mlx->map_scale;
			p[i].y *= mlx->map_scale;
			p[i].z *= mlx->map_altitude;
			++i;
		}
		a = a->next;
	}
}

int		ft_isfit(t_fdf *mlx, t_coord a, t_coord b)
{
<<<<<<< HEAD:src/ft_draw.c
=======
//	printf("sealevel: %d, a.h: %d, b.h: %d\n", mlx->sealevel, a.z, b.z);
>>>>>>> 7284a58473a197e0d976cc58753c80145f72ff82:tibo_fdf/src2/ft_draw.c
	if (a.y * mlx->win_width + a.x + mlx->map_origin < 0)
		return (0);
	else if (a.y * mlx->win_width + a.x + mlx->map_origin > mlx->last_pix)
		return (0);
	else if (b.y * mlx->win_width + b.x + mlx->map_origin < 0)
		return (0);
	else if (b.y * mlx->win_width + b.x + mlx->map_origin > mlx->last_pix)
		return (0);
	else if (abs(a.x + mlx->omx) + 1 > (mlx->win_width / 2)
	|| abs(b.x + mlx->omx) + 1 > (mlx->win_width / 2))
		return (0);
	else
		return (1);
}

void	ft_drawline(t_fdf *mlx, t_coord a, t_coord b,\
		void (*f)(t_coord, t_coord, t_coord*, t_coord*))
{
	t_coord		a2d;
	t_coord		b2d;

	(*f)(a, b, &a2d, &b2d);
	if (!(ft_isfit(mlx, a2d, b2d)))
		return ;
	if (a.h <= mlx->sealevel || b.h <= mlx->sealevel)
		return ;
	ft_bresenham(mlx, a2d, b2d);
}

void	ft_draw(t_fdf *mlx, t_list *list3d)
{
	size_t	i;
	t_coord	*coord;
	t_coord	*coord_next;
	t_list	*copy;

<<<<<<< HEAD:src/ft_draw.c
	copy = ft_drawtool(mlx, list3d);
=======
	
		// prints the origin...
	mlx->img_data[mlx->map_origin] = mlx->color + 100;
	mlx->img_data[mlx->map_origin + 1] = mlx->color + 100;
	mlx->img_data[mlx->map_origin - 1] = mlx->color + 100;
	mlx->img_data[mlx->map_origin + mlx->win_width] = mlx->color + 100;
	mlx->img_data[mlx->map_origin - mlx->win_width] = mlx->color + 100;

	copy = ft_copylist(list3d);
	ft_centermap(mlx, copy);
	ft_rotmap(mlx, copy);
	ft_scale_coord(mlx, copy);
>>>>>>> 7284a58473a197e0d976cc58753c80145f72ff82:tibo_fdf/src2/ft_draw.c
	while (copy)
	{
		i = 0;
		coord = (t_coord*)copy->content;
		while (i < copy->content_size)
		{
			if (i + 1 < copy->content_size)
				ft_drawline(mlx, coord[i], coord[i + 1], mlx->projection);
			if (copy->next && i < (copy->next)->content_size)
			{
				coord_next = (t_coord*)(copy->next)->content;
				ft_drawline(mlx, coord[i], coord_next[i], mlx->projection);
			}
			i++;
		}
		copy = copy->next;
	}
	ft_lstdel(&copy, &ft_lstdel_cnt);
}
