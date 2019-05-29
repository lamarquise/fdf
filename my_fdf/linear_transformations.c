

#include "fdf.h"

		// all this shit will need to be freed at some point, but when ???

t_f3d	*rot_90_r()
{
	t_f3d	*trans;

	if (!(trans = (t_f3d *)malloc(sizeof(t_f3d) * 3)))
		return (0);
	
	trans[0].x = 0;		//x
	trans[0].y = -1;
	trans[0].z = 0;
	
	trans[1].x = 1;		//y
	trans[1].y = 0;
	trans[1].z = 0;
	
	trans[2].x = 0;		//z
	trans[2].y = 0;
	trans[2].z = 1;
	return (trans);
}

t_f3d	*rot_90_l()
{
	t_f3d	*trans;

	if (!(trans = (t_f3d *)malloc(sizeof(t_f3d) * 3)))
		return (0);
	
	trans[0].x = 0;		//x
	trans[0].y = 1;
	trans[0].z = 0;
	
	trans[1].x = -1;		//y
	trans[1].y = 0;
	trans[1].z = 0;
	
	trans[2].x = 0;		//z
	trans[2].y = 0;
	trans[2].z = 1;
	return (trans);
}

t_f3d	*push_r()
{
	t_f3d	*trans;

	if (!(trans = (t_f3d *)malloc(sizeof(t_f3d) * 3)))
		return (0);
	
	trans[0].x = cos(45 * PI / 180);		//x
	trans[0].y = 0;
	trans[0].z = -sin(45 * PI / 180);
	
	trans[1].x = 0;		//y
	trans[1].y = 1;
	trans[1].z = 0;
	
	trans[2].x = sin(45 * PI / 180);		//z
	trans[2].y = 0;
	trans[2].z = cos(45 * PI / 180);
	return (trans);
}

