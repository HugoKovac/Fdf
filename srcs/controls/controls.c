/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:36:39 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/28 15:27:32 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	zoom(int keycode, t_mlx *mlx)
{
	re_win(mlx);
	mlx->ratio += 2;
	draw_tile(mlx, mlx->l);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}

void	unzoom(int keycode, t_mlx *mlx)
{
	if (mlx->ratio > 4)
	{
		re_win(mlx);
		mlx->ratio -= 2;
		draw_tile(mlx, mlx->l);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
}

void	moves(int keycode, t_mlx *mlx)
{
	re_win(mlx);
	if (keycode == ARROW_RIGHT)
		mlx->origin.x -= 10;
	else if (keycode == ARROW_LEFT)
		mlx->origin.x += 10;
	else if (keycode == ARROW_UP)
		mlx->origin.y += 10;
	else if (keycode == ARROW_DOWN)
		mlx->origin.y -= 10;
	draw_tile(mlx, mlx->l);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}

void	step(int keycode, t_mlx *mlx)
{
	re_win(mlx);
	if (keycode == MAIN_PAD_P)
		mlx->z_size++;
	else
		mlx->z_size--;
	draw_tile(mlx, mlx->l);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}

int	choose(int keycode, t_mlx *mlx)
{
	if (keycode >= 0)
	{
		if (keycode == MAIN_PAD_ESC)
			shut_win(keycode, mlx);
		else if (keycode == MAIN_PAD_PLUS)
			zoom(keycode, mlx);
		else if (keycode == MAIN_PAD_MINUS)
			unzoom(keycode, mlx);
		else if (keycode == ARROW_RIGHT
			|| keycode == ARROW_LEFT
			|| keycode == ARROW_UP
			|| keycode == ARROW_DOWN)
			moves(keycode, mlx);
		else if (keycode == MAIN_PAD_P
			|| keycode == MAIN_PAD_O)
			step(keycode, mlx);
		else if (keycode == MAIN_PAD_C)
			carr(keycode, mlx);
		else if (keycode == MAIN_PAD_I)
			iso(keycode, mlx);
		put_menu(mlx);
		return (1);
	}
	return (0);
}
