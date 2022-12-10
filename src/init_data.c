/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:00:52 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/10 10:00:50 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	reserve_memory(t_fdf *fdf)
{
	int	i;

	i = -1;
	fdf->z = (int **)malloc(sizeof(int *) * fdf->rows);
	while (++i < fdf->colums)
		fdf->z[i] = (int *)malloc(sizeof(int) * fdf->colums);
	i = -1;
	fdf->color = (int **)malloc(sizeof(int *) * fdf->rows);
	while (++i < fdf->colums)
		fdf->color[i] = (int *)malloc(sizeof(int) * fdf->colums);
}

static void	fill_color(t_fdf *fdf,char **data, int i, int j)
{
	if (data[1])
		fdf->color[i][j] = (int)strtol(data[1], NULL, 16);
	else
		fdf->color[i][j] = 0xFFFFFF;
	free_split(data);
}

static	void	fill_z(t_fdf *fdf, int fd)
{
	int		i;
	char	*line;
	char 	**split;
	char 	**data;
	int		j;

	reserve_memory(fdf);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		j = -1;
		while (split[++j])
		{
			data = ft_split(split[j],',');
			fdf->z[i][j]=ft_atoi(data[0]);
			fill_color(fdf, data, i, j);
		}
		free_split(split);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

void	init_size(t_fdf *fdf)
{
	fdf->zoom = 30;
	fdf->flat = 0.30;
	fdf->x_move = 500;
	fdf->y_move = 250;
	fdf->perspective = 'i';
}

t_fdf *init_data_fdf(char *path)
{
	int		cols;
	int		rows;
	int		fd;
	t_fdf	*fdf;
	
	fd = open(path, O_RDONLY);
	if (read(fd, 0, 0) || fd < 0)
		return (NULL);
	if (!check_map(fd, &rows, &cols))
	{
		ft_printf("Error: Badly formatted map\n");
		return (NULL);
	}
	close(fd);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->colums = cols;
	fdf->rows = rows;
	init_size(fdf);
	fd = open(path, O_RDONLY);
	fill_z(fdf, fd);
	close(fd);
	return (fdf);
}
