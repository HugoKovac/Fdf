/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:54:09 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/28 15:16:48 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return ((placement / distance));
}

unsigned int	get_light(int start, int end, double percentage)
{
	return (((1 - percentage) * start + percentage * end));
}

unsigned int	get_base_color(int z, t_utils *l)
{
	double	per;

	per = percent(l->z_min, l->z_max, z);
	if (per < 0.2)
		return (COLOR_DISCO);
	else if (per < 0.4)
		return (COLOR_BRICK_RED);
	else if (per < 0.6)
		return (COLOR_FLAMINGO);
	else if (per < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

unsigned int	wich_color(t_2d tmp, t_2d beg, t_2d end, t_2d delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (tmp.color == end.color)
		return (tmp.color);
	if (delta.x > delta.y)
		percentage = percent(beg.x, end.x, tmp.x);
	else
		percentage = percent(beg.y, end.y, tmp.y);
	red = get_light((beg.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = get_light((beg.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = get_light(beg.color & 0xFF,
			end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
