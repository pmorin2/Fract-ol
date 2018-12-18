/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:39:38 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/18 13:58:00 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"
#include "libft.h"

int	frac_cal(t_mlx *mlx)
{
	if (!ft_strcmp(mlx->name, "mandelbrot"))
		mandelbrot_calc(mlx);
	else if (!ft_strcmp(mlx->name, "julia"))
		julia_calc(mlx);
	return (0);
}

int	mlx_start(t_mlx *mlx)
{
	if (!ft_strcmp(mlx->name, "mandelbrot"))
		mandelbrot_init(mlx);
	else if (!ft_strcmp(mlx->name, "julia"))
		julia_init(mlx);
	mlx_hook(mlx->win, 6, 1L < 6, julia_mouse, mlx);
	mlx_key_hook(mlx->win, keypress, mlx);
    mlx_mouse_hook(mlx->win, mouse_zoom, mlx);
    mlx_loop(mlx->init);
	return (0);
}

int	mlx_set(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, W_WIN, H_WIN, "Fractol");
	mlx->img = mlx_new_image(mlx->init, W_WIN, H_WIN);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line
									, &mlx->endian);
	mlx->color = 255;
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2 || !ft_strcmp(av[1], "Julia") || !ft_strcmp(av[1], "Mandelbrot"))
	{
		ft_putendl("Usage : ./fractol (Julia | Mandelbrot)");
		return(0);
	}
	mlx_set(&mlx);
	mlx.name = av[1];
	mlx_start(&mlx);
	return (0);
}
