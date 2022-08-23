/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 11:39:20 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/18 17:05:32 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_segment(char const *s, char c)
{
	size_t	counter;
	int		i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*clone;
	size_t	i;

	clone = (char *)malloc(sizeof (char) * (n + 1));
	if (clone == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		clone[i] = s1[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}

static void	*destroy_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	tab_counter;
	t_save	y;

	if (s == NULL)
		return (NULL);
	strs = malloc(sizeof (char *) * (count_segment(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	tab_counter = 0;
	y.j = -1;
	while (s[++y.j])
	{
		if (s[y.j] == c)
			continue ;
		y.i = 0;
		while (s[y.j + y.i] && s[y.j + y.i] != c)
			y.i++;
		strs[tab_counter++] = ft_strndup(&s[y.j], y.i);
		if (strs == NULL)
			return (destroy_strs(strs));
		y.j += y.i - 1;
	}
	strs[tab_counter] = NULL;
	return (strs);
}
