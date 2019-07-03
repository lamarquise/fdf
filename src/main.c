/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:31:49 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/02 22:58:46 by tlamart          ###   ########.fr       */
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
	if (!(list = ft_parser(&file)))
		return (ft_error("An error occured during parsing the file\n"));
	ft_fdf(&list);
	return (0);
}
