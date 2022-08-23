/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:55:00 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/28 15:12:26 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ter_dw(int beg, int end)
{
	if (beg < end)
		return (1);
	return (-1);
}

void	draw_line(t_2d beg, t_2d end, t_mlx *mlx)
{
	t_2d	delta;
	t_2d	sign;
	t_2d	tmp;

	delta.x = abs(end.x - beg.x);
	delta.y = abs(end.y - beg.y);
	sign.x = ter_dw(beg.x, end.x);
	sign.y = ter_dw(beg.y, end.y);
	mlx->error[0] = delta.x - delta.y;
	tmp = beg;
	while (tmp.x != end.x || tmp.y != end.y)
	{
		put_pixel_image(mlx, tmp.x, tmp.y, wich_color(tmp, beg, end, delta));
		mlx->error[1] = mlx->error[0] * 2;
		if (mlx->error[1] > -delta.y)
		{
			mlx->error[0] -= delta.y;
			tmp.x += sign.x;
		}
		if (mlx->error[1] < delta.x)
		{
			mlx->error[0] += delta.x;
			tmp.y += sign.y;
		}
	}
}
