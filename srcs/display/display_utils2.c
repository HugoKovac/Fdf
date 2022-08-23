/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:49:28 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/27 15:53:17 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	shut_win(int keycode, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

void	re_win(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, mlx->x_size, mlx->x_size);
	mlx->add = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_length, &mlx->endian);
}
