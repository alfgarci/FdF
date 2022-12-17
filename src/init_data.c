/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:00:52 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/11 22:05:48 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	reserve_memory(t_fdf *fdf)
{
	int	i;

	i = -1;
	fdf->z = (int **)malloc(sizeof(int *) * fdf->rows);
	if (!fdf->z)
		exit(-1);
	fdf->color = (int **)malloc(sizeof(int *) * fdf->rows);
	if (!fdf->color)
	{
		free(fdf->z);
		exit(-1);
	}
	while (++i < fdf->rows)
	{
		fdf->color[i] = (int *)malloc(sizeof(int) * fdf->colums);
		if (!fdf->color[i])
			free_error_color(fdf, i);
	}
	i = -1;
	while (++i < fdf->rows)
	{
		fdf->z[i] = (int *)malloc(sizeof(int) * fdf->colums);
		if (!fdf->z[i])
			free_error_z(fdf, i);
	}
}

static void	fill(t_fdf *fdf, char **data, int i, int j)
{
	if (ft_strncmp(data[0], "\n", 1) != 0)
	{
		fdf->z[i][j] = ft_atoi(data[0]);
		if (data[1] != NULL)
			fdf->color[i][j] = str_to_hex(data[1]);
		else
			fdf->color[i][j] = 0xFFFFFF;
	}
	free_split(data);
}

static	void	read_file_to_init(t_fdf *fdf, int fd)
{
	int		i;
	char	*line;
	char	**split;
	char	**data;
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
			data = ft_split(split[j], ',');
			fill(fdf, data, i, j);
		}
		free_split(split);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

static void	init_size(t_fdf *fdf)
{
	if (fdf->colums * fdf->rows < 500)
		fdf->zoom = 30;
	else if (fdf->colums * fdf->rows < 1000)
		fdf->zoom = 10;
	else
		fdf->zoom = 2;
	fdf->flat = 0.3;
	fdf->x_move = 500;
	fdf->y_move = 250;
	fdf->view = 'i';
}

t_fdf	*init_data_fdf(char *path)
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
	read_file_to_init(fdf, fd);
	close(fd);
	return (fdf);
}
