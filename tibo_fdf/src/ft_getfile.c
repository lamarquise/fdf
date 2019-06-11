/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:39:09 by tlamart           #+#    #+#             */
/*   Updated: 2019/04/26 17:47:24 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_dellall(char **s1, char **s2)
{
	if (*s1 == *s2)
	{
		ft_strdel(s1);
		return (NULL);
	}
	else
	{
		ft_strdel(s1);
		ft_strdel(s2);
		return (NULL);
	}
}

static int	ft_checkbuf(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) || ft_isspace(*str))
			str++;
		else if ((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)))
			str++;
		else
			return (0);
	}
	return (1);
}

char		*ft_getfile(const int fd)
{
	char	*file;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	if (!(file = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret > 0)
	{
		buf[ret] = '\0';
		tmp = file;
		if (!ft_checkbuf(buf))
			return (ft_dellall(&file, &tmp));
		file = ft_strjoin(file, buf);
		ft_strdel(&tmp);
		if (!file)
			return (NULL);
	}
	return (file);
}
