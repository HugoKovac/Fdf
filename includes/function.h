/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:04:22 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/28 14:53:49 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "includes.h"

/*main.c*/
void			put_menu(t_mlx *mlx);
/*display_utils.c*/
void			find_size(t_mlx *mlx, t_utils l);
void			find_origin(t_mlx *mlx, t_utils *l);
void			init_mlx(t_mlx *mlx, int x, int y);
void			put_pixel_image(t_mlx *mlx, int x, int y, unsigned int color);
/*display_utils2.c*/
void			shut_win(int keycode, t_mlx *mlx);
void			re_win(t_mlx *mlx);
/*parsing.c*/
int				ft_parse(char *file, t_utils *l);
/*parsing_utils.c*/
int				init_mega_tab(t_utils *l, int size);
int				freeif(char *str, char ***mega_tab, int rtn);
int				closeif(int fd1, int fd2, int rtn);
/*draw_line.c*/
void			draw_line(t_2d f, t_2d s, t_mlx *mlx);
/*draw_tile.c*/
t_2d			trans(t_2d map_coor, t_mlx *mlx, int z, t_utils *l);
void			draw_tile(t_mlx *mlx, t_utils *l);
void			draw_tile_carr(t_mlx *mlx, t_utils *l);
/*controls.c*/
void			zoom(int keycode, t_mlx *mlx);
void			unzoom(int keycode, t_mlx *mlx);
int				choose(int keycode, t_mlx *mlx);
/*view.c*/
void			carr(int keycode, t_mlx *mlx);
void			iso(int keycode, t_mlx *mlx);
/*color.c*/
unsigned int	get_base_color(int z, t_utils *l);
unsigned int	wich_color(t_2d tmp, t_2d beg, t_2d end, t_2d delta);

#endif