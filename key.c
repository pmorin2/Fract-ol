/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:41 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/18 14:04:52 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "key.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

int	key_zoom_move(int key, t_mlx *mlx)
{
	if (key == RIGHT_ARROW)
		mlx->x1 += 10 / mlx->zoom;
	else if (key == LEFT_ARROW)
		mlx->x1 -= 10 / mlx->zoom;
	else if (key == UP_ARROW)
		mlx->y1 -= 10 / mlx->zoom;
	else if (key == DOWN_ARROW)
		mlx->y1 += 10 / mlx->zoom;
	else if (key == K_PLUS)
		mlx->zoom += 10;
	else if (key == K_MINUS)
		mlx->zoom -= 10;
	else if (key == PAGE_UP)
	  mlx->imax += 10;
	else if (key == PAGE_DOWN)
	  mlx->imax -= 10;
	return (0);
}

int	keypress(int key, t_mlx *mlx)
{
	if (key == K_TAB)
		mlx->palette_nbr = (mlx->palette_nbr + 1) % 9;
	else if (key == K_ESC)
	{
		mlx_destroy_image(mlx->init, mlx->img);
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	else if (key == RIGHT_ARROW || key == LEFT_ARROW || key == UP_ARROW
			|| key == DOWN_ARROW || key == K_PLUS || key == K_MINUS
		 || key == PAGE_UP || key == PAGE_DOWN)
		key_zoom_move(key, mlx);
	else if (key == CTRL && !ft_strcmp(mlx->name, "julia"))
		mlx->mouse_act = (mlx->mouse_act + 1) % 2;
	else if (key == CLEAR)
		frac_init(mlx);
	else
		return (0);
	mlx_destroy_image(mlx->init, mlx->img);
	mlx->img = mlx_new_image(mlx->init, W_WIN, H_WIN);
    mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line
									 , &mlx->endian);
	frac_cal(mlx);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4 || button == 1)
	{
		mlx->x1 = (x / mlx->zoom + mlx->x1) - (x / (mlx->zoom * 1.3));
		mlx->y1 = (y / mlx->zoom + mlx->y1) - (y / (mlx->zoom * 1.3));
		mlx->zoom *= 1.3;
	}
	else if (button == 5 || button == 2)
	{
		mlx->x1 = (x / mlx->zoom + mlx->x1) - (x / (mlx->zoom / 1.3));
		mlx->y1 = (y / mlx->zoom + mlx->y1) - (y / (mlx->zoom / 1.3));
		mlx->zoom /= 1.3;
	}
	else
		return (0);
	mlx_destroy_image(mlx->init, mlx->img);
    mlx->img = mlx_new_image(mlx->init, W_WIN, H_WIN);
    mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line
                                     , &mlx->endian);
    frac_cal(mlx);
	return (0);
}

int	julia_mouse(int x, int y, t_mlx *mlx)
{
	if (ft_strcmp(mlx->name, "julia") || mlx->mouse_act == 0)
		return (0);
	mlx->c_r = (double)(x / W_WIN);
	mlx->c_i = (double)(y / H_WIN);
	mlx_destroy_image(mlx->init, mlx->img);
    mlx->img = mlx_new_image(mlx->init, W_WIN, H_WIN);
    mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line
                                     , &mlx->endian);
	frac_cal(mlx);
	return (0);
}
