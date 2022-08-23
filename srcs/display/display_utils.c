/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:48:02 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/25 17:22:30 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

/*
*Find tile size at init
*/
void	find_size(t_mlx *mlx, t_utils l)
{
	if ((mlx->x_size - (l.marge * 2)) / l.x_len
		< (mlx->y_size - (l.marge * 2)) / l.y_len)
		mlx->ratio = ((mlx->x_size - (l.marge * 2)) / l.x_len) / 5 * 4;
	else
		mlx->ratio = ((mlx->y_size - (l.marge * 2)) / l.x_len) / 5 * 4;
	if (mlx->ratio < 4)
		mlx->ratio = 4;
}

/*
*Find coor origin at init
*/
void	find_origin(t_mlx *mlx, t_utils *l)
{
	t_2d	tmp;
	t_2d	tmp2;

	mlx->origin.x = 0;
	mlx->origin.y = 0;
	tmp.x = l->x_len - 1;
	tmp.y = 0;
	tmp2.x = 0;
	tmp2.y = l->y_len - 1;
	tmp = trans(tmp, mlx, ft_atoi(l->map_parse[tmp.y][tmp.x]), l);
	tmp2 = trans(tmp2, mlx, ft_atoi(l->map_parse[tmp2.y][tmp2.x]), l);
	mlx->origin.x = (mlx->x_size - tmp.x + abs(tmp2.x)) / 2;
	tmp2.x = l->x_len - 1;
	tmp2.y = l->y_len - 1;
	tmp2 = trans(tmp2, mlx, ft_atoi(l->map_parse[tmp2.y][tmp2.x]), l);
	mlx->origin.y = ((mlx->y_size - tmp2.y) / 3) * 2;
}

/*
*Create image and window
*/
void	init_mlx(t_mlx *mlx, int x, int y)
{
	mlx->x_size = x;
	mlx->y_size = y;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, x, y, "FDF");
	mlx->img = mlx_new_image(mlx->mlx, x, y);
	mlx->add = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_length, &mlx->endian);
}

void	put_pixel_image(t_mlx *mlx, int x, int y, unsigned int color)
{
	char	*pixel;

	if (y < mlx->y_size - 1 && x < mlx->x_size - 1 && x >= 0 && y >= 0)
	{
		pixel = mlx->add + (y * mlx->line_length + x * (mlx->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}
