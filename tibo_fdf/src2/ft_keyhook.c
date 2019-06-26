/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:58:28 by tlamart           #+#    #+#             */
/*   Updated: 2019/06/26 15:11:32 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		ft_redraw(t_fdf *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img_ptr);
	if (!(mlx->img_ptr = mlx_new_image(mlx->ptr, mlx->win_width,\
		mlx->win_height)))
		return (0);
	mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr,\
	&mlx->bpp, &mlx->s_l, &mlx->endian);
	ft_draw(mlx, *mlx->list_coord);
	mlx_clear_window(mlx->ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (0);
}

void	ft_init_keytab(t_key *tab)
{
	tab[0].keycode = 53;
	tab[0].f = &ft_quitfdf;
	tab[1].keycode = 116;
	tab[1].f = &ft_increase_altitude;
	tab[2].keycode = 121;
	tab[2].f = &ft_decrease_altitude;
	tab[3].keycode = 13;
	tab[3].f = &ft_up;
	tab[4].keycode = 1;
	tab[4].f = &ft_down;
	tab[5].keycode = 0;
	tab[5].f = &ft_left;
	tab[6].keycode = 2;
	tab[6].f= &ft_right;
	tab[7].keycode = 69;
	tab[7].f = ft_zoom_in;
	tab[8].keycode = 78;
	tab[8].f = ft_zoom_out;
	tab[9].keycode = 8;
	tab[9].f = ft_color;
	tab[10].keycode = 49;
	tab[10].f = &ft_change_projection;

	tab[11].keycode = 17;
	tab[11].f = &ft_rot_z_left;
	tab[12].keycode = 16;
	tab[12].f = &ft_rot_z_right;
	tab[13].keycode = 32;
	tab[13].f = &ft_rot_x_left;
	tab[14].keycode = 5;
	tab[14].f = &ft_rot_x_right;
	tab[15].keycode = 4;
	tab[15].f = &ft_rot_y_left;
	tab[16].keycode = 38;
	tab[16].f = &ft_rot_y_right;
	

}

int		ft_keyhook(int keycode, void *param)
{
	t_fdf			*mlx;
	static t_key	keytab[42] = {{42, NULL}};
	int				i;

	i = 0;
	mlx = (t_fdf*)param;
	if (keytab[0].keycode == 42)
		ft_init_keytab(keytab);
	while (i < 17)
	{
		if (keycode == keytab[i].keycode)
			return (keytab[i].f(mlx));
		i++;
	}
	return (0);
}
