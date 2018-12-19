/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:39:38 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/19 16:19:24 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"
#include "libft.h"

int			frac_init(t_mlx *mlx)
{
	if (!ft_strcmp(mlx->name, "mandelbrot"))
		mandelbrot_init(mlx);
	else if (!ft_strcmp(mlx->name, "julia"))
		julia_init(mlx);
	else if (!ft_strcmp(mlx->name, "burningship"))
		burningship_init(mlx);
	else if (!ft_strcmp(mlx->name, "spider"))
		spider_init(mlx);
	else if (!ft_strcmp(mlx->name, "bonus_2"))
		bonus_2_init(mlx);
	else if (!ft_strcmp(mlx->name, "bonus_3"))
		bonus_3_init(mlx);
	else if (!ft_strcmp(mlx->name, "bonus_4"))
		bonus_4_init(mlx);
	else if (!ft_strcmp(mlx->name, "bonus_5"))
		bonus_5_init(mlx);
	mlx_string_put(mlx->init, mlx->win, 10, 10, 16777215,
					ft_strjoin("iteration max = ", ft_itoa(mlx->imax)));
	mlx_string_put(mlx->init, mlx->win, 10, 30, 16777215,
					ft_strjoin("zoom = ", ft_itoa(mlx->zoom)));
	return (0);
}

int			frac_cal(t_mlx *mlx)
{
	if (!ft_strcmp(mlx->name, "mandelbrot"))
		mandelbrot_calc(mlx);
	else if (!ft_strcmp(mlx->name, "julia"))
		julia_calc(mlx);
	else if (!ft_strcmp(mlx->name, "burningship"))
		burningship_calc(mlx);
	else if (!ft_strcmp(mlx->name, "spider"))
		spider_calc(mlx);
	else if (!ft_strcmp(mlx->name, "bonus_2"))
		bonus_2_calc(mlx);
	else if (!ft_strcmp(mlx->name, "bonus_3"))
		bonus_3_calc(mlx);
	else if (!ft_strcmp(mlx->name, "bonus_4"))
		bonus_4_calc(mlx);
	else if (!ft_strcmp(mlx->name, "bonus_5"))
		bonus_5_calc(mlx);
	mlx_string_put(mlx->init, mlx->win, 10, 10, 16777215,
					ft_strjoin("iteration max = ", ft_itoa(mlx->imax)));
	mlx_string_put(mlx->init, mlx->win, 10, 30, 16777215,
					ft_strjoin("zoom = ", ft_itoa(mlx->zoom)));
	return (0);
}

static int	mlx_start(t_mlx *mlx)
{
	frac_init(mlx);
	mlx_hook(mlx->win, 6, 1L < 6, julia_mouse, mlx);
	mlx_key_hook(mlx->win, keypress, mlx);
	mlx_mouse_hook(mlx->win, mouse_zoom, mlx);
	mlx_loop(mlx->init);
	return (0);
}

static int	mlx_set(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, W_WIN, H_WIN, "Fractol");
	mlx->img = mlx_new_image(mlx->init, W_WIN, H_WIN);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line
									, &mlx->endian);
	mlx->color = 255;
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2 || (ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "mandelbrot")
					&& ft_strcmp(av[1], "burningship")
					&& ft_strcmp(av[1], "spider") && ft_strcmp(av[1], "bonus_2")
					&& ft_strcmp(av[1], "bonus_3")
					&& ft_strcmp(av[1], "bonus_4")
					&& ft_strcmp(av[1], "bonus_5")))
	{
		ft_putendl("Usage : ./fractol (julia | mandelbrot | burningship \
| spider | bonus_2 | bonus_3 | bonus_4 | bonus_5)");
		return (0);
	}
	mlx_set(&mlx);
	mlx.name = av[1];
	mlx_start(&mlx);
	return (0);
}
