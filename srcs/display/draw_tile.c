/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:31:28 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/28 14:51:14 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

/*
*Transform map coor in pixel coor to isometric
*/
t_2d	trans(t_2d map_coor, t_mlx *mlx, int z, t_utils *l)
{
	t_2d	pixel;

	if (mlx->carr)
	{
		map_coor.x *= mlx->ratio;
		map_coor.y *= mlx->ratio;
		pixel.x = map_coor.x + (mlx->x_size - (mlx->ratio * l->x_len)) / 2;
		pixel.y = map_coor.y + mlx->origin.y;
	}
	else
	{	
		map_coor.x *= (mlx->ratio * 86 / 100);
		map_coor.y *= mlx->ratio;
		pixel.x = (map_coor.x - map_coor.y) * cos(0.523599) + mlx->origin.x;
		pixel.y = -(z * mlx->z_size) + (map_coor.x + map_coor.y)
			* sin(0.523599) + mlx->origin.y;
		pixel.color = map_coor.color;
	}
	return (pixel);
}

void	case1(t_mlx *mlx, t_utils *l, t_2d *curr, t_2d *com)
{
	com->x = curr->x + 1;
	com->y = curr->y;
	l->z1 = ft_atoi(l->map_parse[curr->y][curr->x]);
	l->z2 = ft_atoi(l->map_parse[com->y][com->x]);
	com->color = get_base_color(l->z1, l);
	curr->color = get_base_color(l->z2, l);
	draw_line(trans(*curr, mlx, l->z1, l), trans(*com, mlx, l->z2, l), mlx);
}

void	case2(t_mlx *mlx, t_utils *l, t_2d *curr, t_2d *com)
{
	com->x = curr->x;
	com->y = curr->y + 1;
	l->z1 = ft_atoi(l->map_parse[curr->y][curr->x]);
	l->z2 = ft_atoi(l->map_parse[com->y][com->x]);
	com->color = get_base_color(l->z1, l);
	curr->color = get_base_color(l->z2, l);
	draw_line(trans(*curr, mlx, l->z1, l), trans(*com, mlx, l->z2, l), mlx);
}

/*
*draw each tile in iso
*/
void	draw_tile(t_mlx *mlx, t_utils *l)
{
	t_2d	curr;
	t_2d	com;

	curr.y = -1;
	while (++curr.y < l->y_len)
	{
		curr.x = -1;
		while (++curr.x < l->x_len)
		{
			if (curr.x != l->x_len - 1)
				case1(mlx, l, &curr, &com);
			if (curr.y != l->y_len - 1)
				case2(mlx, l, &curr, &com);
		}
	}
}
