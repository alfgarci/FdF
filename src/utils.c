/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:09:07 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/10 09:11:44 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_num(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	module(int num)
{
	if (num > 0)
		return (num);
	return (num * -1);
}

void	free_split(char **split)
{
	int	aux;

	aux = -1;
	while (*(split + ++aux))
		free(*(split + aux));
	free(split);
}
