/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:51:06 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/28 14:51:33 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	carr(int keycode, t_mlx *mlx)
{
	re_win(mlx);
	mlx->carr = 1;
	draw_tile(mlx, mlx->l);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}

void	iso(int keycode, t_mlx *mlx)
{
	re_win(mlx);
	mlx->carr = 0;
	draw_tile(mlx, mlx->l);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
