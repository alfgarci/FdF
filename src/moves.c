/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:03:10 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/11 16:17:32 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 27 && (fdf->zoom - 1) > 0)
	{
		fdf->zoom -= 1;
		fdf->y_move += 20;
	}
	else if (keycode == 24)
	{
		fdf->zoom += 1;
		fdf->y_move -= 20;
	}
}

int	keys_p(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 45)
		fdf->flat -= 0.1;
	else if (keycode == 46)
		fdf->flat += 0.1;
	else if (keycode == 27 || keycode == 24)
		zoom(keycode, fdf);
	else if (keycode == 125)
		fdf->y_move += 20;
	else if (keycode == 126)
		fdf->y_move -= 20;
	else if (keycode == 124)
		fdf->x_move += 20;
	else if (keycode == 123)
		fdf->x_move -= 20;
	else if (keycode == 34)
		fdf->view = 'i';
	else if (keycode == 31)
		fdf->view = 'o';
	re_draw(fdf);
	return (0);
}
