/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:35:26 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/26 22:40:11 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx_macos/mlx.h"
# include <math.h>

# define WIN_H 1080
# define WIN_W 1920
# define ANGLE 0.523599
# define SHIFT 10
# define ZOOM_SHIFT 0.25
# define ROT_SHIFT 0.01
# define WHITE 0xFFFFFF
# define CARROT 0xFFA500
# define YELLOW 0xFFFF00
# define GRASS 0x00FF00
# define AQUA 0x00FFFF
# define RED 0xFF0000
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_P 35
# define KEY_R 15
# define KEY_MINUS 27
# define KEY_PLUS 24
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct s_map
{
	int	w;
	int	h;
	int	**z_matrix;
	int	**color;
	int	min_z;
	int	max_z;
	int	iscolor;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;
	int		shift_x;
	int		shift_y;
	float	zoom;
	int		iso;
	float	altitude;
	float	rot_x;
	float	rot_y;
	float	rot_z;
}	t_fdf;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_coord;

void	parse_file(t_map *map, char *file);
void	alloc_map(t_map *map);
int		get_width(t_map *map, char *line);
t_map	*init_map(char *file);
void	create_map(t_map **map, char *file);
void	free_map(t_map *map);
void	free_split(char **split);
void	free_fdf(t_fdf *fdf);
void	free_all(t_fdf *fdf);
void	ft_error(char *msg);
void	fill_matrix(t_map *map, int fd);
int		set_color(t_map *map, char *s);
void	get_min_max_z(t_map *map);
void	convert_to_lower(char *s);
int		ft_max(int a, int b);
void	init_mlx(t_fdf *fdf);
void	default_fdf(t_fdf *fdf);
void	mlx_main(t_map *map);
void	draw_menu(t_fdf *fdf);
void	draw(t_fdf *fdf);
int		interpolate(int start, int end, double percent);
int		get_color(t_coord pix, t_coord start, t_coord end, t_coord delta);
void	img_pixel_put(t_fdf *fdf, int x, int y, int color);
int		z_to_color(t_fdf *fdf, int z);
t_coord	new_coord(int i, int j, t_fdf *fdf);
void	init_bresenham(t_coord *start, t_coord *end,
			t_coord *delta, t_coord *sign);
void	bresenham(t_fdf *fdf, t_coord start, t_coord end);
void	rot_x(t_fdf *fdf, int *y, int *z);
void	rot_y(t_fdf *fdf, int *x, int *z);
void	rot_z(t_fdf *fdf, int *x, int *y);
void	isometric(t_fdf *fdf, int *x, int *y, int z);
int		close_win(t_fdf *fdf);
int		deal_key(int key, t_fdf *fdf);
void	move(int key, t_fdf *fdf);
void	zoom(int key, t_fdf *fdf);
void	altitude(int key, t_fdf *fdf);
void	rot(int key, t_fdf *fdf);
int		check_arg_map(char *str);
int		check_arg_num(char c);

#endif
