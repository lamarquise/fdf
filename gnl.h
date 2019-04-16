/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:59 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/12 20:28:18 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# define DELIM '\n'

typedef struct	s_glst
{
	char			*s;
	int				fd;
	struct s_glst	*next;
}				t_glst;

int		gnl(char **l, char **s, int b_size, int fd);

#endif
