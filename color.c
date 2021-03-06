/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:33:36 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/19 16:26:06 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	palette(t_mlx *mlx, int i)
{
	if (mlx->palette_nbr == 0)
		return ((i * 10) % 16777216);
	else if (mlx->palette_nbr == 1)
		return ((i * 10 * 256) % 16777216);
	else if (mlx->palette_nbr == 2)
		return ((i * 10 * 65536) % 16777216);
	else if (mlx->palette_nbr == 3)
		return (((i * 10 * 65536) % 16777216) + ((i * 10 * 256) % 65536)
				+ ((i * 10) % 256));
	else if (mlx->palette_nbr == 4)
		return (((i * 10 * 65536) % 16777216) + ((i * 20 * 256) % 65536)
				+ ((i * 30) % 256));
	else if (mlx->palette_nbr == 5)
		return (((i * 30 * 65536) % 16777216) + ((i * 10 * 256) % 65536)
				+ ((i * 20) % 256));
	else if (mlx->palette_nbr == 6)
		return (((i * 42 * 65536) % 16777216) + ((i * 420 * 256) % 65536)
				+ ((i * 4) % 256));
	else if (mlx->palette_nbr == 7)
		return (((i * 4 * 65536) % 16777216) + ((i * 42 * 256) % 65536)
				+ ((i * 420) % 256));
	else
		return (0);
}
