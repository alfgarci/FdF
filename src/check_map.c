/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:48:42 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/10 10:10:18 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_elements(char *line)
{
	int	i;
	int	elem;

	i = 0;
	elem = 0;
	while (line[i] != '\n')
	{
		while (line[i] != '\n' && line[i] == 32)
			i++;
		if (line[i] != '\n')
			elem++;
		while (line[i] != '\n' && line[i] != 32)
			i++;
	}
	return (elem);
}

int	check_map(int fd, int *r, int *c)
{
	int		cols;
	int		elems;
	int		rows;
	int		first_line;
	char	*line;

	rows = 0;
	line = get_next_line(fd);
	cols = count_elements(line);
	while (line)
	{
		elems = count_elements(line);
		if (elems != cols)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		rows++;
	}
	free(line);
	*r = rows;
	*c = cols;
	return (1);
}
