/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:47:37 by alfgarci          #+#    #+#             */
/*   Updated: 2022/11/19 13:28:02 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"

int	ex(int keycode, void *vars)
{
	(void)vars;
	if (keycode == 53)
		exit(0);
	ft_printf("You presed %d", keycode);
	return 0;
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;

	(void)mlx;
	(void)win;
	(void)ac;
	(void)av;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Ventana");
	mlx_key_hook(win, ex, NULL);
	int	x = -1;
	int	y = -1;
	while (++x < 500)
	{
		y = -1;
		while (++y < 500)
		{
			if (x < y)
				mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
		}
	}
	mlx_loop(mlx);
	return (0);
}
