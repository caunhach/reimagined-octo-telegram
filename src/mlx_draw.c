/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:05:02 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/28 01:06:22 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_menu(t_fdf *fdf)
{
	int		y;

	y = 0;
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 15, WHITE,
		"<< Button Control >>");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 50, WHITE, "Shift: W A S D");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 25, WHITE, "Zoom: + / -");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 25, WHITE,
		"Altitude Scale: UP/DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 25, WHITE, "Rotate:");
	mlx_string_put(fdf->mlx, fdf->win, 30, y += 25, WHITE,
		"  x (cw / ccw): Z / X");
	mlx_string_put(fdf->mlx, fdf->win, 30, y += 25, WHITE,
		"  y (cw / ccw): C / V");
	mlx_string_put(fdf->mlx, fdf->win, 30, y += 25, WHITE,
		"  z (cw / ccw): B / N");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 25, WHITE,
		"Iso <-> Parallel: P");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 25, WHITE,
		"Default: R");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 25, WHITE, "ESC: Quit");
}

t_coord	new_coord(int i, int j, t_fdf *fdf)
{
	t_coord	coord;

	coord.x = i * fdf->zoom;
	coord.y = j * fdf->zoom;
	coord.z = fdf->map->z_matrix[j][i];
	coord.z *= (fdf->zoom / 10) * fdf->altitude;
	if (fdf->map->iscolor)
		coord.color = fdf->map->color[j][i];
	else
		coord.color = z_to_color(fdf, coord.z);
	rot_x(fdf, &coord.y, &coord.z);
	rot_y(fdf, &coord.x, &coord.z);
	rot_z(fdf, &coord.x, &coord.y);
	isometric(fdf, &coord.x, &coord.y, coord.z);
	coord.x += fdf->shift_x;
	coord.y += fdf->shift_y;
	return (coord);
}

void	draw(t_fdf *fdf)
{
	int	i;
	int	j;

	ft_bzero(fdf->img->addr, WIN_H * WIN_W * (fdf->img->bpp / 8));
	if (fdf->zoom)
	{
		j = -1;
		while (++j < fdf->map->h)
		{
			i = -1;
			while (++i < fdf->map->w)
			{
				if (i < fdf->map->w - 1)
					bresenham(fdf, new_coord(i, j, fdf),
						new_coord(i + 1, j, fdf));
				if (j < fdf->map->h - 1)
					bresenham(fdf, new_coord(i, j, fdf),
						new_coord(i, j + 1, fdf));
			}
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	draw_menu(fdf);
}
