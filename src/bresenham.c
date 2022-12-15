/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:49:55 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/15 16:53:39 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	perspective(t_point *point, t_fdf *fdf)
{
	double	x_o;
	double	y_o;

	x_o = point->x;
	y_o = point->y;
	if (fdf->view == 'i')
	{
		point->x = (x_o - y_o) * cos(0.52);
		point->y = (x_o + y_o) * sin(0.52) - (point->z * fdf->flat);
	}
}

static void	resize(t_point	*s, t_point *e, t_fdf *fdf)
{
	s->x *= fdf->zoom;
	e->x *= fdf->zoom;
	s->y *= fdf->zoom;
	e->y *= fdf->zoom;
	s->x += fdf->x_move;
	e->x += fdf->x_move;
	s->y += fdf->y_move;
	e->y += fdf->y_move;
}

static t_alg	*get_init_data(t_point *s, t_point *e)
{
	t_alg	*instance;
	int		max;
	double	copy_x;
	double	copy_y;

	copy_x = s->x;
	copy_y = s->y;
	instance = (t_alg *)malloc(sizeof(t_alg));
	instance->x_move = e->x - s->x;
	instance->y_move = e->y - s->y;
	max = max_num(module(instance->x_move), module(instance->y_move));
	instance->x_move /= max;
	instance->y_move /= max;
	instance->len_pixel = 0;
	while ((int)(copy_x - e->x) || (int)(copy_y - e->y))
	{
		copy_x += instance->x_move;
		copy_y += instance->y_move;
		instance->len_pixel++;
	}
	return (instance);
}

void	bresenham(t_point *s, t_point *e, t_fdf *fdf)
{
	t_alg	*instance;
	int		i;
	int		color_s;
	int		color_e;
	int		color_tmp;

	color_s = s->color;
	color_e = e->color;
	perspective(s, fdf);
	perspective(e, fdf);
	resize(s, e, fdf);
	instance = get_init_data(s, e);
	i = 0;
	while ((int)(s->x - e->x) || (int)(s->y - e->y))
	{
		color_tmp = get_color(color_s, color_e, instance->len_pixel, i++);
		if (s->x >= 0 && s->x < HEIGHT && s->y >= 0 && s->y < WIDTH)
			my_mlx_pixel_put(fdf->data, s->x, s->y, color_tmp);
		s->x += instance->x_move;
		s->y += instance->y_move;
	}
	free(instance);
	free(s);
	free(e);
}
