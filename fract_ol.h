/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:33:46 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/18 13:52:39 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define H_WIN 800
# define W_WIN 800

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
	char			*name;
	int				mouse_act;
}					t_mlx;

void	mandelbrot_calc(t_mlx *mlx);
int		mandelbrot_init(t_mlx *mlx);
void	julia_calc(t_mlx *mlx);
int		julia_init(t_mlx *mlx);
void	put_pixel_to_img(t_mlx *mlx, int color, int x, int y);
int		keypress(int key, t_mlx *mlx);
int		julia_mouse(int x, int y, t_mlx *mlx);
int		palette(t_mlx *mlx, int i);
int		frac_cal(t_mlx *mlx);
int		mouse_zoom(int button, int x, int y, t_mlx *mlx);
#endif
