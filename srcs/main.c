/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:38:27 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/28 15:25:27 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	put_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->mlx_win,
		10, 0, 0x00FFFF00, "Zoom : + / -");
	mlx_string_put(mlx->mlx, mlx->mlx_win,
		10, 30, 0x00FFFF00, "Move : arrows");
	mlx_string_put(mlx->mlx, mlx->mlx_win,
		10, 60, 0x00FFFF00, "Isometric view : I");
	mlx_string_put(mlx->mlx, mlx->mlx_win,
		10, 90, 0x00FFFF00, "Cartesian view : C");
	mlx_string_put(mlx->mlx, mlx->mlx_win,
		10, 120, 0x00FFFF00, "Z + : P");
	mlx_string_put(mlx->mlx, mlx->mlx_win,
		10, 150, 0x00FFFF00, "Z - : O");
	mlx_string_put(mlx->mlx, mlx->mlx_win,
		10, 180, 0x00FFFF00, "Cartesian view : C");
	mlx_string_put(mlx->mlx, mlx->mlx_win,
		10, 210, 0x00FFFF00, "Quit : ESC");
}

void	find_max_min(t_utils *l)
{
	t_2d	pt;

	l->z_min = ft_atoi(l->map_parse[0][0]);
	l->z_max = ft_atoi(l->map_parse[0][0]);
	pt.y = -1;
	while (l->map_parse[++pt.y])
	{
		pt.x = -1;
		while (l->map_parse[pt.y][++pt.x])
		{
			if (ft_atoi(l->map_parse[pt.y][pt.x]) > l->z_max)
				l->z_max = ft_atoi(l->map_parse[pt.y][pt.x]);
			if (ft_atoi(l->map_parse[pt.y][pt.x]) < l->z_min)
				l->z_max = ft_atoi(l->map_parse[pt.y][pt.x]);
		}
	}
}

int	main(int ac, char **av)
{
	t_utils	l;
	t_mlx	mlx;

	if (ac != 2)
		return (1);
	if (!ft_parse(av[1], &l))
		return (1);
	init_mlx(&mlx, 2600, 1300);
	l.marge = 10;
	mlx.l = &l;
	mlx.z_size = 3;
	find_size(&mlx, l);
	find_max_min(&l);
	mlx.carr = 0;
	find_origin(&mlx, &l);
	draw_tile(&mlx, &l);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	put_menu(&mlx);
	mlx_hook(mlx.mlx_win, 2, 0, choose, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
