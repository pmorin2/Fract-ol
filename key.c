/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:41 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/17 18:30:48 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "key.h"
#include "mlx.h"
#include <stdlib.h>

int	keypress(int key, t_mlx *mlx)
{
	if (key == K_TAB)
		mlx->palette_nbr = (mlx->palette_nbr + 1) % 4;
	else if (key == K_ESC)
	{
		mlx_destroy_image(mlx->init, mlx->img);
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	/*else if (key == RIGHT_ARROW)
		mlx->move_x += 10;
	else if (key == LEFT_ARROW)
		mlx->move_x -= 10;
	else if (key == UP_ARROW)
		mlx->move_y -= 10;
	else if (key == DOWN_ARROW)
	mlx->move_y += 10;*/
	else if (key == K_PLUS)
		mlx->zoom += 10;
	else if (key == K_MINUS)
		mlx->zoom -= 10;
	mlx_destroy_image(mlx->init, mlx->img);
	mlx->img = mlx_new_image(mlx->init, W_WIN, H_WIN);
    mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line
									 , &mlx->endian);
	mandelbrot_calc(mlx);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
	{
		mlx->zoom += 50;
	mlx->x1 = ( x - W_WIN / 2) / 2 / mlx->zoom + mlx->x1;
	mlx->y1 = ( y - H_WIN / 2) / 2 / mlx->zoom + mlx->y1;
	mlx_destroy_image(mlx->init, mlx->img);
    mlx->img = mlx_new_image(mlx->init, W_WIN, H_WIN);
    mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line
                                     , &mlx->endian);
    mandelbrot_calc(mlx);
	}
	return (0);
}
