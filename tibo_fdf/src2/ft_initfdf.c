/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initfdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:42:23 by tlamart           #+#    #+#             */
/*   Updated: 2019/06/27 14:24:02 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	ft_mapsize(t_list *list, t_fdf *mlx)
{
	mlx->map_width = 0;
	mlx->map_height = 0;
	while (list)																// could do this directly in the parsing, might make things easier...
	{
		mlx->map_height += 1;
		if ((int)list->content_size > mlx->map_width)
			mlx->map_width = (int)list->content_size;
		list = list->next;
	}
	mlx->map_width *= 10;		// width init = nb coord.x * 10
	mlx->map_height *= 10;		// same with y
	mlx->map_scale = 1;
	while (mlx->map_width * mlx->map_scale * 2 < MIN_WIN_WIDTH \
		&& mlx->map_height * mlx->map_scale * 2 < MIN_WIN_HEIGHT)
		mlx->map_scale += 1;
	mlx->map_altitude = 1;
//	ft_printf("MAP SIZE\n\nmap width = %d, map height = %d\n", mlx->map_width, mlx->map_height);
//	ft_printf("scale = %d\n", mlx->map_scale);
//	ft_stop();
}


/*

static void	ft_winsize(t_fdf *mlx)
{
	mlx->win_width = 2 * mlx->map_width * mlx->map_scale;
	mlx->win_height = 2 * mlx->map_height * mlx->map_scale;
	if (mlx->win_width > MAX_WIN_WIDTH)
		mlx->win_width = MAX_WIN_WIDTH;
	else if (mlx->win_width < MIN_WIN_WIDTH)
		mlx->win_width = MIN_WIN_WIDTH;
	if (mlx->win_height > MAX_WIN_HEIGHT)
		mlx->win_height = MAX_WIN_HEIGHT;
	else if (mlx->win_height < MIN_WIN_HEIGHT)
		mlx->win_height = MIN_WIN_HEIGHT;
	mlx->last_pix = mlx->win_width * mlx->win_height - 1;
//	ft_printf("WINDOW SIZE\n\nwin width = %d, win height = %d\n", mlx->win_width, mlx->win_height);
//	ft_stop();
}

*/


/*

void		ft_setmap_origin(t_fdf *mlx)
{
	int		mid_map_line;
	int		mid_map_col;
	int		mid_win_line;
	int		mid_win_col;

	mid_map_line = mlx->map_width * mlx->map_scale / 2;
	mid_map_col = mlx->map_height * mlx->map_scale / 2;
	mid_win_line = mlx->win_width / 2;
	mid_win_col = mlx->win_height / 2;
	mlx->map_origin = (mid_win_line - mid_map_line) / 2;
	mlx->map_origin += (mid_win_col - mid_map_col) / 2 * mlx->win_width;
//	ft_printf("SET ORIGIN\n\nx = %d, y = %d\n", mlx->map_origin % mlx->win_width, mlx->map_origin / mlx->win_width);
//	ft_stop();
}

*/


static int	ft_createwin(t_fdf *mlx)
{
	if (!(mlx->ptr = mlx_init()))
		return (1);
	if (!(mlx->win_ptr = mlx_new_window(\
		mlx->ptr, mlx->win_width, mlx->win_height, "fdf")))
		return (2);
	if (!(mlx->img_ptr = mlx_new_image(\
		mlx->ptr, mlx->win_width, mlx->win_height)))
		return (3);
	if (!(mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,\
		&mlx->s_l, &mlx->endian)))											// ok i don't quite get how this works...
		return (4);
//	ft_printf("bpp = %d, size line = %d, endian = %d\n", mlx->bpp, mlx->s_l, mlx->endian);
//	ft_stop();
	return (0);
}

int			ft_initfdf(t_list *lst3d, t_fdf *mlx)
{
	int		status;

	mlx->color = 0x00FF6600;
	mlx->projection = &ft_getcoord_par;
	ft_mapsize(lst3d, mlx);					// could be done in parsing...
//	ft_winsize(mlx);

	mlx->win_height = 1000;											// decent window proportions...
	mlx->win_width = 1600;
	mlx->last_pix = 1000 * 1600 - 1;

//	ft_setmap_origin(mlx);

	mlx->map_origin = 1600 * 500 + 800;



	status = ft_createwin(mlx);

	mlx->r_x = 0;
	mlx->r_y = 0;
	mlx->r_z = 0;

	return (status);
}







