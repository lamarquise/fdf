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
