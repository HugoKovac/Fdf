/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:01:00 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/27 17:57:23 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_2d
{
	int				x;
	int				y;
	unsigned int	color;
}	t_2d;

typedef struct s_utils
{
	int		x_len;
	int		y_len;
	char	*gnl;
	char	***map_parse;
	int		fd1;
	int		fd2;
	int		marge;
	int		i;
	int		z1;
	int		z2;
	int		z_min;
	int		z_max;
}	t_utils;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*add;
	int		line_length;
	int		bpp;
	int		endian;
	int		x_size;
	int		y_size;
	int		z_size;
	int		ratio;
	int		carr;
	double	alpha;
	double	beta;
	double	gamma;
	t_2d	origin;
	t_utils	*l;
	int		error[2];
}	t_mlx;

#endif
