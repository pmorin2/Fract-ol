/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:01:54 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/17 18:08:04 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

int		mandelbrot_init(t_mlx *mlx)
{
	mlx->x1 = -2.5;
	mlx->y1 = -2.0;
	mlx->imax = 50;
	mlx->zoom = 150,0;
	mlx->palette_nbr = 0;
	return (0);
}

void	mandelbrot_calc(t_mlx *mlx)
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
			mlx->c_r = x / mlx->zoom + mlx->x1;
			mlx->c_i= y / mlx->zoom + mlx->y1;
			mlx->z_r = 0;
			mlx->z_i = 0;
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

void	mandelbrot(t_mlx *mlx)
{
	mandelbrot_init(mlx);
	mandelbrot_calc(mlx);
	mlx_key_hook(mlx->win, keypress, mlx);
	mlx_mouse_hook(mlx->win, mouse_zoom, mlx);
	mlx_loop(mlx->init);
}
