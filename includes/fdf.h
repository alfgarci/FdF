/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:58:09 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/10 10:07:07 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int 	endian;
}			t_data;

typedef	struct	s_fdf
{
	int		colums;
	int		rows;
	int 	**z;
	int		**color;
	char	perspective;
	int		zoom;
	float	flat;
	int		x_move;
	int		y_move;
	void	*mlx;
	void	*win;
	t_data	*data;
}				t_fdf;

/*init_data.c*/
t_fdf	*init_data_fdf(char *path);

/*print.c*/
void	draw(t_fdf *fdf);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	re_draw(t_fdf *fdf);

/*color.c*/
int		get_color(int start, int end, int max, int i);

/*bresenham.c*/
void	bresenham(float x, float y, float x2, float y2, t_fdf *fdf);

/*check_map.c*/
int		check_map(int fd, int *r, int *c);

/*utils.c*/
int		max_num(int a, int b);
int		module(int num);
void	free_split(char **split);

#endif

