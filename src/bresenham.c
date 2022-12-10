/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:49:55 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/10 10:27:53 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	perspective(float *x, float *y, float z, char p)
{
	float	x_o = *x;
	float	y_o = *y;

	if (p == 'i')
	{
		*x = (x_o - y_o) * cos(0.52);
		*y = (x_o + y_o) * sin(0.52) - z;
	}
}

static void	resize(float *x, float *y, float *x2, float *y2, t_fdf *fdf)
{
	*x *= fdf->zoom;
	*x2 *= fdf->zoom;
	*y *= fdf->zoom;
	*y2 *= fdf->zoom;
	*x += fdf->x_move;
	*x2 += fdf->x_move;
	*y += fdf->y_move;
	*y2 += fdf->y_move;
}

void	bresenham(float x, float y, float x2, float y2, t_fdf *fdf)
{
	float	x_move;
	float	y_move;
	int		max;
	float	z;
	float	z2;
	int		color_s;
	int 	i;
	int		color_e;
	float		cp_x;
	int		num_pixel = 0;
	float	cp_y;

	color_s = fdf->color[(int)y][(int)x];
	color_e = fdf->color[(int)y2][(int)x2];
	z = fdf->z[(int)y][(int)x] * fdf->flat;
	z2 = fdf->z[(int)y2][(int)x2] * fdf->flat;
	perspective(&x, &y, z, fdf->perspective);
	perspective(&x2, &y2, z2, fdf->perspective);
	resize(&x, &y, &x2, &y2, fdf);
	x_move = x2 - x;
	y_move = y2 - y;
	max = max_num(module(x_move), module(y_move));
	x_move /= max;
	y_move /= max;
	cp_x = x;
	cp_y = y;

	while ((int)(cp_x - x2) || (int)(cp_y - y2))
	{
		cp_x += x_move;
		cp_y += y_move;
		num_pixel++;
	}

	i = 0;
	while ((int)(x - x2) || (int)(y - y2))
	{
		int act_col = get_color(color_s, color_e, num_pixel, i++);
		if (x >= 0 && x < 1000 && y >= 0 && y < 800)
			my_mlx_pixel_put(fdf->data , x, y, act_col);
		x += x_move;
		y += y_move;
	}
}
