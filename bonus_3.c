/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:03:42 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/19 15:51:27 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

int			bonus_3_init(t_mlx *mlx)
{
	mlx->x1 = -1.65;
	mlx->y1 = -1.65;
	mlx->imax = 50;
	mlx->zoom = 240.0;
	mlx->palette_nbr = 0;
	mlx->mouse_act = 0;
	mlx->c_r = 0.285;
	mlx->c_i = 0.01;
	bonus_3_calc(mlx);
	return (0);
}

static int	bonus_3_while(int i, double tmp, t_mlx *mlx)
{
	while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4
			&& i < mlx->imax)
	{
		tmp = mlx->z_r;
		mlx->z_r = (mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i) + mlx->c_r;
		mlx->z_i = sin(2 * mlx->z_i * tmp) + mlx->c_i;
		i++;
	}
	return (i);
}

void		bonus_3_calc(t_mlx *mlx)
{
	double	x;
	double	y;
	int		i;

	x = -1;
	while (++x < H_WIN)
	{
		y = -1;
		while (++y < W_WIN)
		{
			mlx->z_r = x / mlx->zoom + mlx->x1;
			mlx->z_i = y / mlx->zoom + mlx->y1;
			i = bonus_3_while(0, 0.0, mlx);
			if (i == mlx->imax)
				put_pixel_to_img(mlx, 0, x, y);
			else
				put_pixel_to_img(mlx, palette(mlx, i), x, y);
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}
