/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:07:25 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/10 10:17:26 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	percentage(int start, int end, int current)
{
	float	actual;
	float	distance;

	actual = current - start;
	distance = end - start;
	if (distance == 0)
		return (1);
	else
		return (actual / distance);
}

static int	get_color_part(int start, int end, double per)
{
	return (((1 - per) * start) + (per * end));
}

int	get_color(int start, int end, int max, int i)
{
	int		red;
	int		blue;
	int		green;
	float	per;

	per = percentage(0, max, i);
	red = get_color_part((start >> 16) & 0xFF, (end >> 16) & 0xFF, per);
	green = get_color_part((start >> 8) & 0xFF, (end >> 8) & 0xFF, per);
	blue = get_color_part(start & 0xFF, end & 0xFF, per);
	return ((red << 16) | (green << 8) | blue);
}
