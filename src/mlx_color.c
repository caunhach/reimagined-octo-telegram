/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 02:01:34 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/28 02:03:29 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double	percent(int start, int end, int cur)
{
	if (start == end)
		return (1.0);
	return ((double)(cur - start) / (double)(end - start));
}

int	interpolate(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int	get_color(t_coord pix, t_coord start, t_coord end, t_coord delta)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (pix.color == end.color)
		return (pix.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, pix.x);
	else
		percentage = percent(start.y, end.y, pix.y);
	r = interpolate((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
			percentage);
	g = interpolate((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
			percentage);
	b = interpolate(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}

void	img_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	int		pixel;
	char	*dst;

	if (y >= WIN_H || x >= WIN_W || y < 0 || x < 0)
		return ;
	pixel = (y * fdf->img->ll) + (x * (fdf->img->bpp / 8));
	dst = fdf->img->addr + (y * fdf->img->ll) + (x * (fdf->img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	z_to_color(t_fdf *fdf, int z)
{
	double	percentage;

	percentage = percent(fdf->map->min_z, fdf->map->max_z, z);
	if (percentage < 0.2)
		return (AQUA);
	else if (percentage < 0.4)
		return (GRASS);
	else if (percentage < 0.6)
		return (YELLOW);
	else if (percentage < 0.8)
		return (CARROT);
	else
		return (RED);
}
