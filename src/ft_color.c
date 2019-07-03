/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:42:26 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/02 16:30:18 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_fdf *mlx)
{
	static int	color = 0;
	static int	tab[5] = {0xFFFFFF, 0xFF6600, 0xFF0000, 0x00FF00, 0x0000FF};

	color++;
	color %= 5;
	mlx->color = tab[color];
	return (ft_redraw(mlx));
}
