/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:52:32 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/11 15:32:23 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*make_point(int x, int y, t_fdf *fdf)
{
	t_point	*new;

	new = (t_point *)malloc(sizeof(t_point));
	new->x = (double)x;
	new->y = (double)y;
	new->z = fdf->z[y][x];
	new->color = fdf->color[y][x];
	return (new);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_fdf *fdf)
{
	int		y;
	int		x;
	t_point	*pt1;
	t_point	*pt2;

	y = -1;
	while (++y < fdf->rows)
	{
		x = -1;
		while (++x < fdf->colums)
		{
			if (x < fdf->colums - 1)
			{
				pt1 = make_point(x, y, fdf);
				pt2 = make_point(x + 1, y, fdf);
				bresenham(pt1, pt2, fdf);
			}
			if (y < fdf->rows - 1)
			{
				pt1 = make_point(x, y, fdf);
				pt2 = make_point(x, y + 1, fdf);
				bresenham(pt1, pt2, fdf);
			}
		}
	}
}

void	re_draw(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	mlx_clear_window(fdf->mlx, fdf->win);
	fdf->data->img = mlx_new_image(fdf->mlx, HEIGHT, WIDTH);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bpp,
			&fdf->data->line_l, &fdf->data->endian);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img, 0, 0);
}
