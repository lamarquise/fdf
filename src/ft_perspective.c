/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perspective.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:10:09 by erlazo            #+#    #+#             */
/*   Updated: 2019/07/03 08:32:36 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_centermap(t_fdf *mlx, t_list *map)
{
	size_t	i;
	int		y;
	t_coord	*coord_tab;

	y = 0;
	while (map)
	{
		i = 0;
		coord_tab = (t_coord*)map->content;
		while (i < map->content_size)
		{
			coord_tab[i].x = (-mlx->map_width) / 2 + 5 + i * 10;
			coord_tab[i].y = (-mlx->map_height) / 2 + 5 + y * 10;
			++i;
		}
		map = map->next;
		++y;
	}
}

		// redraw window does not work for structural reasons i think...
/*
int		ft_mod_winsize(t_fdf *mlx)
{
	printf("test 1\n");
	ft_clear_mlx(mlx);
	if (mlx->win_type == 1)
	{
		mlx->win_width = 1000;
		mlx->win_height = 700;
		mlx->win_type = 0;
	}
	else
	{
		mlx->win_width = 1400;
		mlx->win_height = 900;
		mlx->win_type = 1;
	}
	if (ft_createwin(mlx) != 0)
	{
		ft_abort(mlx, mlx->list_coord, "window_redraw() failed\n");
		return (0);
	}
	return (ft_redraw(mlx));
}
*/
