/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:31:43 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/19 16:51:06 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"
#include "libft.h"

void	put_pixel_to_img(t_mlx *mlx, int color, int x, int y)
{
	unsigned int real_color;

	real_color = mlx_get_color_value(mlx->init, color);
	if (x < W_WIN && y < H_WIN)
		ft_memcpy(mlx->img_ptr + 4 * W_WIN * y + 4 * x, &real_color
					, sizeof(int));
}
