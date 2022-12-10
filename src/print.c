/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:52:32 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/10 10:11:43 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->rows)
	{
		j = -1;
		while (++j < fdf->colums)
		{
			if (j < fdf->colums - 1)
				bresenham(j, i, j + 1, i, fdf);
			if (i < fdf->rows - 1)
				bresenham(j, i, j, i + 1, fdf);
		}
	}
}

void	re_draw(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	mlx_clear_window(fdf->mlx, fdf->win);
	fdf->data->img = mlx_new_image(fdf->mlx, 1000, 800);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bpp,
			&fdf->data->line_l, &fdf->data->endian);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img, 0, 0);
}
