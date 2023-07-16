/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:25:47 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/28 22:25:50 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	move(int key, t_fdf *fdf)
{
	if (key == KEY_W)
		fdf->shift_y -= SHIFT;
	else if (key == KEY_A)
		fdf->shift_x -= SHIFT;
	else if (key == KEY_S)
		fdf->shift_y += SHIFT;
	else if (key == KEY_D)
		fdf->shift_x += SHIFT;
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == KEY_PLUS)
	{
		if (fdf->zoom < 2147483647)
			fdf->zoom += ZOOM_SHIFT;
	}
	if (key == KEY_MINUS)
	{
		if (fdf->zoom > 0)
			fdf->zoom -= ZOOM_SHIFT;
	}
}

void	altitude(int key, t_fdf *fdf)
{
	if (key == KEY_UP)
	{
		if (fdf->altitude < 10)
			fdf->altitude += 0.1;
	}
	if (key == KEY_DOWN)
	{
		if (fdf->altitude > 0)
			fdf->altitude -= 0.1;
	}
}

void	rot(int key, t_fdf *fdf)
{
	if (key == KEY_Z)
		fdf->rot_x += ROT_SHIFT;
	if (key == KEY_X)
		fdf->rot_x -= ROT_SHIFT;
	if (key == KEY_C)
		fdf->rot_y += ROT_SHIFT;
	if (key == KEY_V)
		fdf->rot_y -= ROT_SHIFT;
	if (key == KEY_B)
		fdf->rot_z += ROT_SHIFT;
	if (key == KEY_N)
		fdf->rot_z -= ROT_SHIFT;
}
