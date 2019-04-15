

#ifndef FDF_H
#define FDF_H

# define ABS(x) x < 0 ? -x : x


# include <stdio.h>



# include "mlx.h"
# include "libft.h"

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_fdf
{
	void	*mlx;
	void	*wind;
	int		size;
	
}				t_fdf;

int		draw_line(t_point *start, t_point *end, t_fdf *fdf);
void	swap_void(void **c1, void **c2);


#endif
