/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 00:46:24 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/02 17:54:19 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MAX_WIN_WIDTH 2400
# define MAX_WIN_HEIGHT 1300
# define MIN_WIN_WIDTH 500
# define MIN_WIN_HEIGHT 500

# define PI 3.1415926535897


# include <stdio.h>			// REMOVE!!!!!!!

# include <math.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

typedef struct	s_coord
{
	int		x;
	int		y;
	int		z;
	int		h;
}				t_coord;

typedef struct	s_fdf
{
	void	*ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	int		last_pix;
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		s_l;
	int		endian;
	int		map_width;
	int		map_height;
	int		map_origin;
	int		map_scale;
	int		map_altitude;
	int		color;
	t_list	**list_coord;
	void	(*projection)(t_coord, t_coord, t_coord*, t_coord*);

	int		r_x;
	int		r_y;
	int		r_z;

	int		omx;
	int		omy;

	int		sealevel;
	int		win_type;

}				t_fdf;

typedef struct	s_line
{
	int		x;
	int		y;
	int		sign;
}				t_line;

typedef struct	s_key
{
	int		keycode;
	int		(*f)(t_fdf *mlx);
}				t_key;

char	*ft_getfile(const int fd);
t_list	*ft_parser(char **file);
int		ft_initfdf(t_list *lst3d, t_fdf *mlx);

void	ft_getcoord_par(t_coord a, t_coord b, t_coord *a2d, t_coord *b2d);
void	ft_getcoord_iso(t_coord a, t_coord b, t_coord *a2d, t_coord *b2d);

void	ft_setmap_origin(t_fdf *mlx);
void	ft_fdf(t_list **list3d);
void	ft_draw(t_fdf *mlx, t_list *list3d);
void	ft_bresenham(t_fdf *mlx, t_coord a, t_coord b);
void	ft_notbresenham(t_fdf *mlx, t_coord a, t_coord b);
int		ft_keyhook(int keycode, void *param);
void	ft_clear_mlx(t_fdf *mlx);
int		ft_redraw(t_fdf *mlx);


int		ft_quitfdf(t_fdf *mlx);
int		ft_increase_altitude(t_fdf *mlx);
int		ft_decrease_altitude(t_fdf *mlx);
int		ft_up(t_fdf *mlx);
int		ft_down(t_fdf *mlx);
int		ft_left(t_fdf *mlx);
int		ft_right(t_fdf *mlx);
int		ft_zoom_in(t_fdf *mlx);
int		ft_zoom_out(t_fdf *mlx);
int		ft_color(t_fdf *mlx);
int		ft_change_projection(t_fdf *mlx);
int		ft_proj_type(t_fdf *mlx);
//int		ft_mod_winsize(t_fdf *mlx);
//int		ft_createwin(t_fdf *mlx);
//void	ft_abort(t_fdf *mlx, t_list **list, char *err_msg);
void	ft_clear_mlx(t_fdf *mlx);

int		ft_rot_z_left(t_fdf *mlx);
int		ft_rot_z_right(t_fdf *mlx);
int		ft_rot_x_left(t_fdf *mlx);
int		ft_rot_x_right(t_fdf *mlx);
int		ft_rot_y_left(t_fdf *mlx);
int		ft_rot_y_right(t_fdf *mlx);
void	ft_rotcoord(t_fdf *mlx, t_coord *c);

void	ft_hooks_loop(t_fdf *mlx);


t_list	*ft_copylist(t_list *lst);//, t_fdf *mlx);
void	ft_rotmap(t_fdf *mlx, t_list *map);

void	ft_centermap(t_fdf *mlx, t_list *map);
int		ft_raise_sealevel(t_fdf *mlx);
int		ft_lower_sealevel(t_fdf *mlx);





void	ft_positive_diff_dx_greater_than_dy(\
		t_fdf *mlx, t_coord a, t_coord b, t_line err);

void    ft_positive_diff_dy_greater_than_dx(\
		t_fdf *mlx, t_coord a, t_coord b, t_line err);

void    ft_negative_diff_dx_greater_than_dy(\
		t_fdf *mlx, t_coord a, t_coord b, t_line err);

void    ft_negative_diff_dy_greater_than_dx(\
		t_fdf *mlx, t_coord a, t_coord b, t_line d);

void	ft_stop(void);		// only for debug purpose

void	ft_drawline(t_fdf *mlx, t_coord a, t_coord b,\
		void (*f)(t_coord, t_coord, t_coord*, t_coord*)); // only for test_bresenham

#endif
