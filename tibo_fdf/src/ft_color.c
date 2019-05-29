/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:42:26 by tlamart           #+#    #+#             */
/*   Updated: 2019/04/25 19:46:20 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_fdf *mlx)
{
	mlx->color += 0x00000042;
	mlx->color %= 0x00FFFFFF;
	return (ft_redraw(mlx));
}
