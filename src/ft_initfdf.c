/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initfdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:42:23 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 18:47:24 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

t_coord		*ft_refill(t_coord *tab, size_t size)
{
	t_coord	*ret;
	size_t	i;

	i = 0;
	if (!(ret = (t_coord*)malloc(sizeof(t_coord) * size)))
		return (NULL);
	while (i < size)
	{
		ret[i].x = tab[i].x;
		ret[i].y = tab[i].y;
		ret[i].z = tab[i].z;
		ret[i].h = tab[i].h;
		++i;
	}
	return (ret);
}

t_list		*ft_copylist(t_list *lst)
{
	t_list	*ret;
	t_list	*new;
	t_coord	*imp;

	ret = NULL;
	while (lst)
	{
		imp = (t_coord*)lst->content;
		if (!(imp = ft_refill(imp, lst->content_size))\
			|| !(new = ft_lstcreate((void*)imp, lst->content_size)))
		{
			ft_memdel((void**)&imp);
			ft_lstdel(&ret, &ft_lstdel_cnt);
			return (NULL);
		}
		ft_lstappend(&ret, new);
		lst = lst->next;
	}
	return (ret);
}

static void	ft_mapsize(t_list *list, t_fdf *mlx)
{
	mlx->map_width = 0;
	mlx->map_height = 0;
	while (list)
	{
		mlx->map_height += 1;
		if ((int)list->content_size > mlx->map_width)
			mlx->map_width = (int)list->content_size;
		list = list->next;
	}
	mlx->map_width *= 10;
	mlx->map_height *= 10;
	mlx->map_scale = 1;
	while (mlx->map_width * mlx->map_scale < mlx->win_width - 80
		&& mlx->map_height * mlx->map_scale < mlx->win_height - 80)
		mlx->map_scale += 1;
	mlx->map_altitude = 1;
}

static int	ft_createwin(t_fdf *mlx)
{
	if (!(mlx->ptr = mlx_init()))
		return (1);
	if (!(mlx->win_ptr = mlx_new_window(\
		mlx->ptr, mlx->win_width, mlx->win_height, "fdf")))
		return (2);
	if (!(mlx->win_ptr2 = mlx_new_window(\
		mlx->ptr, mlx->win_width, mlx->win_height, "fdf2")))
		return (2);
	if (!(mlx->img_ptr = mlx_new_image(\
		mlx->ptr, mlx->win_width, mlx->win_height)))
		return (3);
	if (!(mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
		&mlx->s_l, &mlx->endian)))
		return (4);
	return (0);
}

int			ft_initfdf(t_list *lst3d, t_fdf *mlx)
{
	mlx->color = 0x00FFFFFF;
	mlx->projection = &ft_getcoord_par;
	mlx->win_height = 700;
	mlx->win_width = 600;
	mlx->last_pix = mlx->win_width * mlx->win_height - 1;
	ft_mapsize(lst3d, mlx);
	mlx->map_origin = (mlx->win_width) * (mlx->win_height / 2)
	+ mlx->win_width / 2;
	mlx->omy = 0;
	mlx->omx = 0;
	mlx->sealevel = -1;
	mlx->r_x = 0;
	mlx->r_y = 0;
	mlx->r_z = 0;
	return (ft_createwin(mlx));
}
