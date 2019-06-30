/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perspective.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:10:09 by erlazo            #+#    #+#             */
/*   Updated: 2019/06/30 15:35:01 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_centermap(t_fdf *mlx, t_list *map)
{
	int		i;
	int		y;
	t_coord	*coord_tab;

	y = 0;
	while(map)
	{
		i = 0;
		coord_tab = (t_coord*)map->content;
		while (i < map->content_size)
		{
			printf("x: %i, y: %i\n", coord_tab[i].x, coord_tab[i].y);
			coord_tab[i].x = (-mlx->map_width) / 2 + i * 10;
			coord_tab[i].y = (-mlx->map_height) / 2 + y * 10;
			printf("modified x: %i, y: %i\n", coord_tab[i].x, coord_tab[i].y);
			++i;
		}
		map = map->next;
		++y;
	}
}
