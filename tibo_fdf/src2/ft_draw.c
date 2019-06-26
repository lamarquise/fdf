/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:44:02 by tlamart           #+#    #+#             */
/*   Updated: 2019/06/26 15:11:30 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	ft_getcoord_par(t_coord a, t_coord b, t_coord *a2d, t_coord *b2d)
{
/*	a2d->x = a.x - a.y;
	a2d->y = -a.z + a.y;
	b2d->x = b.x - b.y;
	b2d->y = -b.z + b.y;	*/
	a2d->x = a.x + a.z / 2;
	a2d->y = a.y - a.z / 2;
	b2d->x = b.x + b.z / 2;
	b2d->y = b.y - b.z / 2;	
//	ft_printf("GET 2D COORD\n\na.x = %d\ta.y = %d\nb.x = %d\tb.y = %d\n", a2d->x, a2d->y, b2d->x, b2d->y);
//	ft_stop();
}

void	ft_scale_coord(t_fdf *mlx, t_coord *a, t_coord *b)
{
	a->x *= mlx->map_scale;
	a->y *= mlx->map_scale;
	a->z *= mlx->map_altitude;
	b->x *= mlx->map_scale;
	b->y *= mlx->map_scale;
	b->z *= mlx->map_altitude;
//	ft_printf("SCALE COORD\n\na.x = %d,\ta.y = %d\nb.x = %d\tb.y = %d\n", a->x, a->y, b->x, b->y);
//	ft_stop();
}

int		ft_isfit(t_fdf *mlx, t_coord a, t_coord b)
{
	if (a.y * mlx->win_width + a.x + mlx->map_origin < 0)
		return (0);
	else if (a.y * mlx->win_width + a.x + mlx->map_origin > mlx->last_pix)
		return (0);
	else if (b.y * mlx->win_width + b.x + mlx->map_origin < 0)
		return (0);
	else if (b.y * mlx->win_width + b.x + mlx->map_origin > mlx->last_pix)
		return (0);
	else
		return (1);
}

void	ft_drawline(t_fdf *mlx, t_coord a, t_coord b,\
		void (*f)(t_coord, t_coord, t_coord*, t_coord*))
{
	t_coord		c;
	t_coord		d;
	t_coord		a2d;
	t_coord		b2d;

	c = a;
	d = b;

	ft_rot_coord(mlx, &c);
	ft_rot_coord(mlx, &d);

	ft_scale_coord(mlx, &c, &d);
	(*f)(c, d, &a2d, &b2d);
//	if (b2d.x - a2d.x < 0)
//		return (ft_drawline(mlx, b, a));
	if (!(ft_isfit(mlx, a2d, b2d)))
		return ;
	ft_bresenham(mlx, a2d, b2d);
}

void	ft_draw(t_fdf *mlx, t_list *list3d)
{
	size_t	i;
	t_coord	*coord;
	t_coord	*coord_next;

	while (list3d)
	{
		i = 0;
		coord = (t_coord*)list3d->content;
		while (i < list3d->content_size)
		{
			if (i + 1 < list3d->content_size)
				ft_drawline(mlx, coord[i], coord[i + 1], mlx->projection);
			if (list3d->next && i < (list3d->next)->content_size)
			{
				coord_next = (t_coord*)(list3d->next)->content;
				ft_drawline(mlx, coord[i], coord_next[i], mlx->projection);
			}
			i++;
		}
		list3d = list3d->next;
	}
}
