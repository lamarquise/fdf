/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:51:57 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/03 08:11:52 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static size_t	ft_count(char *line)
{
	size_t	count;

	count = 0;
	while (*line && *line != '\n')
	{
		while (*line && *line != '\n' && ft_isspace(*line))
			line += 1;
		if (*line == '+' || *line == '-' || ft_isdigit(*line))
			count++;
		while (*line && !ft_isspace(*line))
			line += 1;
	}
	return (count);
}

static t_coord	*ft_filltab(t_coord *coord_tab, char **line)
{
	static int	y = -1;
	int			i;

	y++;
	i = 0;
	while (**line && **line != '\n')
	{
		while (**line && **line != '\n' && ft_isspace(**line))
			*line += 1;
		if (**line == '-' || **line == '+' || ft_isdigit(**line))
		{
<<<<<<< HEAD:src/ft_parser.c
			coord_tab[i].x = (i) * 2;
			coord_tab[i].y = y * 2;
			coord_tab[i].z = ft_atoi(*line) * 2;
			coord_tab[i].h = ft_atoi(*line) * 2;
=======
			coord_tab[i].x = (i) * 2;			// this way I know
			coord_tab[i].y = y * 2;				// every coord is
			coord_tab[i].z = ft_atoi(*line) * 2;	// even (div / 2 != 0)
			coord_tab[i].h = ft_atoi(*line) * 2;
//			printf("coord_tab[i].h: %d\n", coord_tab[i].h);
>>>>>>> 7284a58473a197e0d976cc58753c80145f72ff82:tibo_fdf/src2/ft_parser.c
			i++;
		}
		while (**line && !ft_isspace(**line))
			*line += 1;
	}
	if (**line)
		*line += 1;
	return (coord_tab);
}

static t_coord	*ft_newtab(char **line, size_t *size_tab)
{
	t_coord		*coord_tab;

	*size_tab = ft_count(*line);
	if (!(coord_tab = (t_coord*)ft_memalloc(sizeof(t_coord) * *size_tab)))
		return (NULL);
	coord_tab = ft_filltab(coord_tab, line);
	return (coord_tab);
}

t_list			*ft_parser(char **file)
{
	t_list	*list;
	t_list	*new;
	t_coord	*coord_tab;
	size_t	size_tab;
	char	*line;

	list = NULL;
	line = *file;
	while (*line)
	{
		if (!(coord_tab = ft_newtab(&line, &size_tab)) || !(\
			new = ft_lstcreate((void*)coord_tab, size_tab)))
		{
			ft_strdel(file);
			ft_lstdel(&list, &ft_lstdel_cnt);
			return (NULL);
		}
		ft_lstappend(&list, new);
	}
	ft_strdel(file);
	return (list);
}
