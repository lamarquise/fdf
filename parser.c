


#include "fdf.h"

int		read_map(int fd, t_line **lst)
{
	char	*save;
	char	*line;
	t_line	*new;
	t_line	*tmp;

	if (!lst)
		return (0);	
	while (gnl(&line, &save, 16, fd) > 0)
	{
		if(!(new = (t_line *)malloc(sizeof(t_line))))
			return (0);
		new->tab = ft_strsplit(line, ' ');			//secure???
		new->size = str_count(new->tab);
		if (!*lst)
			*lst = new;
		else
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	return (1);
}


t_p3d	**parse_map(int fd)			// or ret an int.... i do tend to pref that...
{
	t_p3d	**ret;
	t_line	*lst;
	t_line	*tmp;		// find i way to forgo this ???
	int		x;
	int		y;

	if(!read_map(fd, &lst))	// makes a list of lines each stored as a tab of strings
		return (0);
	if (!(ret = (t_p3d **)malloc(sizeof(t_p3d *) * (line_list_count(lst) + 1))))
		return (0);	// i think the last one can be null for while...
	y = 0;
	while (lst)	// same as while y < no. of lines
	{
		if (!(ret[y] = (t_p3d *)malloc(sizeof(t_p3d) * (lst->size + 1))))
			return (0);
		x = 0;
		while (x < lst->size)
		{
			ret[y][x].x = x;
			ret[y][x].y = y;
			ret[y][x].z = ft_atoi(tab[y][x]);		// i think....
			++x;
		}
		ret[y][x] = 0;			// does this work???
		++y;
		tmp = lst;
		lst = lst->next;	// also free the tab in lst ???
		free(tmp);	//since we start with 1st and then done with it.
	}
	ret[y] = 0;
	return (ret);
}














