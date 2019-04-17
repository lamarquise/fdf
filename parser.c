


#include "fdf.h"

int		read_map(int fd, t_line **lst)		// we don't send fdf here... fine i guess
{
	char	*save;
	char	*line;
	t_line	*new;
	t_line	*tmp;

	save = ft_strnew(1);
	line = ft_strnew(1);
	if (!lst)
		return (0);	
	while (gnl(&line, &save, 1, fd) > 0)
	{
		if(!(new = (t_line *)malloc(sizeof(t_line))))
			return (0);
		new->tab = ft_strsplit(line, ' ');			//secure???
		new->size = str_count(new->tab);
		new->next = NULL;					// a hugely helpful line !!!
		if (!*lst)
			*lst = new;
		else
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		free(line);
		line = ft_strnew(1);
	}
	return (1);
}

t_p3d	**parse_map(int fd, t_fdf *fdf)			// or ret an int.... i do tend to pref that...
{
	t_p3d	**ret;
	t_line	*lst;
	t_line	*tmp;		// find i way to forgo this ???
	int		x;
	int		y;

//	printf("parse test1\n");

	lst = NULL;
	ret = NULL;
	if(!read_map(fd, &lst))	// makes a list of lines each stored as a tab of strings
		return (0);
//	printf("parse test1/1\n");
	fdf->lon = line_list_count(lst);
//	printf("parse test1/2\n");
	if (!(ret = (t_p3d **)malloc(sizeof(t_p3d *) * fdf->lon)))
		return (0);	// i think the last one can be null for while...
	y = 0;
	fdf->len = lst->size;
	while (lst)	// same as while y < fdf->lon
	{
//		printf("parse test2\n");
		if (!(ret[y] = (t_p3d *)malloc(sizeof(t_p3d) * (fdf->len))))	// no +1 cuz have len
			return (0);
		x = 0;
		while (x < fdf->len)
		{
			ret[y][x].x = x;
			ret[y][x].y = y;
			ret[y][x].z = ft_atoi(&lst->tab[y][x]);		// i think....
			++x;
		}
		++y;
		tmp = lst;
		lst = lst->next;	// also free the tab in lst ???
		free(tmp);	//since we start with 1st and then done with it.
	}
	printf("parse test3\n");
	return (ret);
}














