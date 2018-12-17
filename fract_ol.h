/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:33:46 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/17 17:36:36 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define H_WIN 600
# define W_WIN 600

typedef struct		s_mlx
{
	void			*init;
	void			*win;
	void			*img;
	char			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	int				color;
	double			x1;
	double			y1;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	int				imax;
	double			zoom;
	int				palette_nbr;
}					t_mlx;

void	mandelbrot(t_mlx *mlx);
void	mandelbrot_calc(t_mlx *mlx);
void	put_pixel_to_img(t_mlx *mlx, int color, int x, int y);
int		keypress(int key, t_mlx *mlx);
int		palette(t_mlx *mlx, int i);
int		mouse_zoom(int button, int x, int y, t_mlx *mlx);
#endif
