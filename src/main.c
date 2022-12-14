/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:47:37 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/15 16:52:41 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	(void)argc;
	fdf = init_data_fdf(argv[1]);
	if (fdf == NULL)
		return (-1);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, HEIGHT, WIDTH, "alfgarci's Fdf");
	fdf->data = (t_data *)malloc(sizeof(t_data));
	if (!fdf->data)
	{
		free_fdf(fdf);
		return (-1);
	}
	fdf->data->img = mlx_new_image(fdf->mlx, HEIGHT, WIDTH);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bpp,
			&fdf->data->line_l, &fdf->data->endian);
	draw_background(fdf);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img, 0, 0);
	mlx_key_hook(fdf->win, keys_p, fdf);
	mlx_loop(fdf->mlx);
	free_fdf(fdf);
	return (0);
}
