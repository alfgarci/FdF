/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:09:07 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/11 22:07:28 by alfgarci         ###   ########.fr       */
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

static int	get_value(char c)
{
	int		i;
	char	*base_l;
	char	*base_u;

	base_l = "0123456789abcdef";
	base_u = "0123456789ABCDEF";
	i = -1;
	while (++i < 16)
		if (base_l[i] == c || base_u[i] == c)
			return (i);
	return (-1);
}

int	str_to_hex(char *str)
{
	int		i;
	int		j;
	int		len;
	int		n;

	n = 0;
	len = strlen(str) - 2;
	j = len - 1;
	i = 1;
	while (str[++i])
		n += (get_value(str[i]) * pow(16, j--));
	return (n);
}
