/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:47:37 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/10 10:18:41 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft.h"

/*
void	l()
{
	system("leaks fdf");
}
*/
void	free_fdf(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (++i < fdf->colums)
	{
		free(fdf->z[i]);
		free(fdf->color[i]);
	}
	free(fdf->z);
	free(fdf->color);
	free(fdf->data);
	free(fdf);
}

int	keys_p(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 45)
		fdf->flat -= 0.1;
	else if (keycode == 46)
		fdf->flat += 0.1;
	else if (keycode == 27)
		fdf->zoom -= 1;
	else if (keycode == 24)
		fdf->zoom += 1;
	else if (keycode == 126)
		fdf->y_move -= 15;
	else if (keycode == 125)
		fdf->y_move += 15;
	else if (keycode == 123)
		fdf->x_move -= 15;
	else if (keycode == 124)
		fdf->x_move += 15;
	else if (keycode == 34)
		fdf->perspective = 'i';
	else if (keycode == 31)
		fdf->perspective = 'o';
	re_draw(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	//atexit(l);
	fdf = init_data_fdf(argv[1]);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1000, 800, "alfgarci's Fdf");
	fdf->data = (t_data *)malloc(sizeof(t_data));
	fdf->data->img = mlx_new_image(fdf->mlx, 1000, 800);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bpp,
			&fdf->data->line_l, &fdf->data->endian);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img, 0, 0);
	mlx_key_hook(fdf->win, keys_p, fdf);
	mlx_loop(fdf->mlx);
	/*
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	*/
	free_fdf(fdf);
	return (0);
}
