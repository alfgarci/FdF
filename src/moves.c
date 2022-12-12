/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:03:10 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/12 11:53:13 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"

static void	zoom(int keycode, t_fdf *fdf)
{
	if (keycode == MINUS && (fdf->zoom - 1) > 0)
	{
		fdf->zoom -= 1;
		fdf->y_move += 20;
	}
	else if (keycode == PLUS)
	{
		fdf->zoom += 1;
		fdf->y_move -= 20;
	}
}

int	keys_p(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == N)
		fdf->flat -= 0.1;
	else if (keycode == M)
		fdf->flat += 0.1;
	else if (keycode == MINUS || keycode == PLUS)
		zoom(keycode, fdf);
	else if (keycode == DOWN)
		fdf->y_move += 20;
	else if (keycode == UP)
		fdf->y_move -= 20;
	else if (keycode == RIGHT)
		fdf->x_move += 20;
	else if (keycode == LEFT)
		fdf->x_move -= 20;
	else if (keycode == I)
		fdf->view = 'i';
	else if (keycode == O)
		fdf->view = 'o';
	re_draw(fdf);
	return (0);
}
