/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:44:02 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 20:32:04 by tlamart          ###   ########.fr       */
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
	t_list	*to_free;

	copy = ft_drawtool(mlx, list3d);
	to_free = copy;
	while (copy)
	{
		i = -1;
		coord = (t_coord*)copy->content;
		while (++i < copy->content_size)
		{
			if (i + 1 < copy->content_size)
				ft_drawline(mlx, coord[i], coord[i + 1], mlx->projection);
			if (copy->next && i < (copy->next)->content_size)
			{
				coord_next = (t_coord*)(copy->next)->content;
				ft_drawline(mlx, coord[i], coord_next[i], mlx->projection);
			}
		}
		copy = copy->next;
	}
	ft_lstdel(&to_free, &ft_lstdel_cnt);
}
