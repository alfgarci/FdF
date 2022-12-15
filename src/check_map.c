/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:48:42 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/15 16:52:58 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_elements(char *line)
{
	int	i;
	int	elem;

	i = 0;
	elem = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		while (line[i] != '\n' && line[i] == 32 && line[i] != '\0')
			i++;
		if (line[i] != '\n' && line[i] != '\0')
			elem++;
		while (line[i] != '\n' && line[i] != 32 && line[i] != '\0')
			i++;
	}
	return (elem);
}

int	check_map(int fd, int *r, int *c)
{
	int		cols;
	int		elems;
	int		rows;
	char	*line;

	rows = 0;
	line = get_next_line(fd);
	cols = count_elements(line);
	elems = cols;
	while (line && (elems == cols))
	{
		elems = count_elements(line);
		free(line);
		line = get_next_line(fd);
		rows++;
	}
	free(line);
	if (elems != cols)
		return (0);
	*r = rows;
	*c = cols;
	return (1);
}
