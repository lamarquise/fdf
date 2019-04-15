

#include "fdf.h"

void	swap_void(void **c1, void **c2)		//seems like too many *'s
{
	void	*tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}
