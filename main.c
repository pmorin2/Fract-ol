/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:39:38 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/14 16:51:55 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mlx_start(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_press, mlx);
}

int	mlx_set(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx ->init, W_WIN, H_WIN, "Fractol");
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
	{
		ft_putendl("Usage : ./fractol (Julia | Mandelbrot | ...)");
		return(0);
	}
	mlx_set(&mlx);
	mlx_start(&mlx);
		return (0);
}
