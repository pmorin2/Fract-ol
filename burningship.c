/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:00:43 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/19 15:58:23 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

int			burningship_init(t_mlx *mlx)
{
	mlx->x1 = -2.5;
	mlx->y1 = -2.0;
	mlx->imax = 50;
	mlx->zoom = 200.0;
	mlx->palette_nbr = 0;
	burningship_calc(mlx);
	return (0);
}

static int	burningship_while(int i, double tmp, t_mlx *mlx)
{
	while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4
			&& i < mlx->imax)
	{
		tmp = mlx->z_r;
		mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
		mlx->z_i = fabs(2 * mlx->z_i * tmp) + mlx->c_i;
		i++;
	}
	return (i);
}

void		burningship_calc(t_mlx *mlx)
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
			mlx->c_r = x / mlx->zoom + mlx->x1;
			mlx->c_i = y / mlx->zoom + mlx->y1;
			mlx->z_r = 0;
			mlx->z_i = 0;
			i = burningship_while(0, 0.0, mlx);
			if (i == mlx->imax)
				put_pixel_to_img(mlx, 0, x, y);
			else
				put_pixel_to_img(mlx, palette(mlx, i), x, y);
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}
