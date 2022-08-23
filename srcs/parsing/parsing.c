/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:21:38 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/25 15:03:18 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	line_file(t_utils l)
{
	l.i = 0;
	l.gnl = get_next_line(l.fd1);
	if (!l.gnl)
		return (-1);
	while (l.gnl && ++l.i)
	{
		l.gnl = get_next_line(l.fd1);
	}
	free(l.gnl);
	return (l.i);
}

int	len_x(char ***tab)
{
	int	i;
	int	j;
	int	norm;

	i = 0;
	while (tab[0][i])
		i++;
	norm = i;
	i = 0;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		if (j != norm)
			return (0);
		j++;
	}
	return (norm);
}

int	ft_parse(char *file, t_utils *l)
{
	int	i;

	l->fd1 = open(file, O_RDONLY);
	l->fd2 = open(file, O_RDONLY);
	if (!l->fd1 || !l->fd2)
		return (closeif(l->fd1, l->fd2, 0));
	l->y_len = line_file(*l);
	if (!init_mega_tab(l, l->y_len + 1))
		return (closeif(l->fd1, l->fd2, 0));
	i = -1;
	l->gnl = "";
	while (l->gnl)
	{
		l->gnl = get_next_line(l->fd2);
		if (!l->gnl)
			break ;
		l->map_parse[++i] = ft_split(l->gnl, ' ');
		if (!l->map_parse[i])
			return (freeif(l->gnl, l->map_parse, closeif(l->fd1, l->fd2, 0)));
	}
	l->x_len = len_x(l->map_parse);
	if (l->x_len == 0)
		return (freeif(l->gnl, l->map_parse, closeif(l->fd1, l->fd2, 0)));
	return (freeif(l->gnl, 0, closeif(l->fd1, l->fd2, 1)));
}
