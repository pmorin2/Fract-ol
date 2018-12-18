/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:22:03 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/18 13:54:28 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

int		julia_init(t_mlx *mlx)
{
	mlx->x1 = -1.5;
	mlx->y1 = -1.5;
	mlx->imax = 50;
	mlx->zoom = 250,0;
	mlx->palette_nbr = 0;
	mlx->mouse_act = 0;
	mlx->c_r = 0.285;
	mlx->c_i = 0.01
	julia_calc(mlx);
	return (0);
}

void	julia_calc(t_mlx *mlx)
{
	double x;
	double y;
	int i;
	double tmp;

	x = -1;

	while (++x < H_WIN)
	{
		y = -1;
		while (++y < W_WIN)
		{
			mlx->z_r = x / mlx->zoom + mlx->x1;
			mlx->z_i= y / mlx->zoom + mlx->y1;
			i = 0;
			while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4
					&& i < mlx->imax)
			{
				tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
				mlx->z_i = 2 * mlx->z_i * tmp + mlx->c_i;
				i++;
			}
			if (i == mlx->imax)
				put_pixel_to_img(mlx, 0, x, y);
			else
				put_pixel_to_img(mlx, palette(mlx, i), x, y);
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}
