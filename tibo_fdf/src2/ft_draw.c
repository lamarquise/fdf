/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:44:02 by tlamart           #+#    #+#             */
/*   Updated: 2019/06/27 14:32:12 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	ft_getcoord_par(t_coord a, t_coord b, t_coord *a2d, t_coord *b2d)
{
	a2d->x = a.x + a.z / 2;
	a2d->y = a.y - a.z / 2;
	b2d->x = b.x + b.z / 2;
	b2d->y = b.y - b.z / 2;	
}

void	ft_scale_coord(t_fdf *mlx, t_coord *a, t_coord *b)
{
	a->x *= mlx->map_scale;
	a->y *= mlx->map_scale;
	a->z *= mlx->map_altitude;
	b->x *= mlx->map_scale;
	b->y *= mlx->map_scale;
	b->z *= mlx->map_altitude;
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
	t_coord		a2d;
	t_coord		b2d;

/*	t_coord		c;
	t_coord		d;
	
	c = a;
	d = b;

	ft_rotcoord(mlx, &c);
	ft_rotcoord(mlx, &d);
*/
	ft_scale_coord(mlx, &a, &b);
	(*f)(a, b, &a2d, &b2d);
	if (!(ft_isfit(mlx, a2d, b2d)))
		return ;
	ft_bresenham(mlx, a2d, b2d);
}

void	ft_draw(t_fdf *mlx, t_list *list3d)
{
	size_t	i;
	t_coord	*coord;
	t_coord	*coord_next;
	t_list	*copy;

		// prints the origin...
	mlx->img_data[mlx->map_origin] = mlx->color;
	mlx->img_data[mlx->map_origin + 1] = mlx->color;
	mlx->img_data[mlx->map_origin + mlx->win_width] = mlx->color;
	mlx->img_data[mlx->map_origin + mlx->win_width + 1] = mlx->color;
	

	copy = ft_copylist(list3d, mlx);

	printf("test 1\n");

	printf("lst content size: %zu\n", list3d->content_size);
//	printf("lst next content size: %zu\n", list3d->next->content_size);
	printf("copy content size: %zu\n", copy->content_size);

//	ft_rotmap(mlx, copy);

	printf("test 2\n");
	//scale copy here too



/*	ft_rotmap(mlx, list3d);		// works, but as expected, fucks up the OG

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
*/

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
	// somehow clear copy here...
	ft_lstdel(&copy, &ft_lstdel_cnt);



}
