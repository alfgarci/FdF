/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:58:09 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/11 16:10:55 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# define HEIGHT 1000
# define WIDTH 800

typedef struct s_alg
{
	double	x_move;
	double	y_move;
	int		len_pixel;
}			t_alg;

typedef struct s_point
{
	double	x;
	double	y;
	int		z;
	int		color;
}			t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}			t_data;

typedef struct s_fdf
{
	int		colums;
	int		rows;
	int		**z;
	int		**color;
	char	view;
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
//void	bresenham(float x, float y, float x2, float y2, t_fdf *fdf);
void	bresenham(t_point *s, t_point *e, t_fdf *fdf);

/*check_map.c*/
int		check_map(int fd, int *r, int *c);

/*utils.c*/
int		max_num(int a, int b);
int		module(int num);
void	free_split(char **split);
void	free_fdf(t_fdf *fdf);

/*moves.c*/
int		keys_p(int keycode, t_fdf *fdf);

#endif
