

#include "fdf.h"

void	swap_void(void **c1, void **c2)		//seems like too many *'s
{
	void	*tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

int		line_list_count(t_line *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}

int		str_count(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}
