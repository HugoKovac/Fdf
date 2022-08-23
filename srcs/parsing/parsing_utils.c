/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:03:34 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/20 13:15:35 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	init_mega_tab(t_utils *l, int size)
{
	if (size < 2)
		return (0);
	l->map_parse = malloc(sizeof (char **) * size);
	if (!l->map_parse)
		return (0);
	while (--size >= 0)
		l->map_parse[size] = NULL;
	return (1);
}

int	freeif(char *str, char ***mega_tab, int rtn)
{
	int	i;

	i = -1;
	if (str)
		free(str);
	if (mega_tab)
		while (mega_tab[++i])
			free_tab(mega_tab[i]);
	free(mega_tab);
	return (rtn);
}

int	closeif(int fd1, int fd2, int rtn)
{
	if (fd1)
		close (fd1);
	if (fd2)
		close (fd2);
	return (rtn);
}
