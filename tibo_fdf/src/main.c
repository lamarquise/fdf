/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:31:49 by tlamart           #+#    #+#             */
/*   Updated: 2019/05/28 18:41:06 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>

static int	ft_usage(char *str)
{
	ft_putstr(str);
	return (0);
}

static int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}

void		ft_stop(void)				// SHOULD RM THIS ONE
{
	char	buf[1];

	read(0, buf, 1);
}

/*
static void	ft_putlst(t_list *list)		// SHOULD RM THIS ONE
{
	size_t		i;

	i = 0;
	t_coord	*coord;

	while (list)
	{
		i = 0;
		while (i < list->content_size)
		{
			coord = list->content;
			ft_printf("x = %d y = %d z = %d\n", coord[i].x, coord[i].y, coord[i].z);
			i++;
		}
		ft_stop();
		list = list->next;
	}
}
*/

int			main(int ac, char **av)
{
	int		fd;
	char	*file;
	t_list	*list;

	if (ac != 2)
		return (ft_usage("usage: fdf <file>\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_error("open() failed\n"));
	file = ft_getfile(fd);
	close(fd);
	if (!file)
		return (ft_error("An error occured during reading the file\n"));
//	ft_putendl(file);
//	ft_stop();
	if (!(list = ft_parser(&file)))
		return (ft_error("An error occured during parsing the file\n"));
//	ft_printf("list len = %d\n", ft_lstlen(list));
//	ft_stop();
//	ft_putlst(list);
//	ft_stop();
	ft_fdf(&list);
	return (0);
}
