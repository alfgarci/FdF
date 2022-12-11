/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:01:07 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/11 22:02:20 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **split)
{
	int	aux;

	aux = -1;
	while (*(split + ++aux))
		free(*(split + aux));
	free(split);
}

void	free_fdf(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (++i < fdf->rows)
	{
		free(fdf->z[i]);
		free(fdf->color[i]);
	}
	free(fdf->z);
	free(fdf->color);
	free(fdf->data);
	free(fdf);
}
