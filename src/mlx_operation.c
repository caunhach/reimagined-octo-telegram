/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:34:21 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/28 17:41:26 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rot_x(t_fdf *fdf, int *y, int *z)
{
	float	old_y;

	old_y = *y;
	*y = (*y * cos(fdf->rot_x)) + (*z * sin(fdf->rot_x));
	*z = (-old_y * sin(fdf->rot_x)) + (*z * cos(fdf->rot_x));
}

void	rot_y(t_fdf *fdf, int *x, int *z)
{
	float	old_x;

	old_x = *x;
	*x = (*x * cos(fdf->rot_y)) - (*z * sin(fdf->rot_y));
	*z = (old_x * sin(fdf->rot_y)) + (*z * cos(fdf->rot_y));
}

void	rot_z(t_fdf *fdf, int *x, int *y)
{
	float	old_x;

	old_x = *x;
	*x = (*x * cos(fdf->rot_z)) - (*y * sin(fdf->rot_z));
	*y = (old_x * sin(fdf->rot_z)) + (*y * cos(fdf->rot_z));
}

void	isometric(t_fdf *fdf, int *x, int *y, int z)
{
	int	old_x;
	int	old_y;

	if (!fdf->iso)
		return ;
	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(ANGLE);
	*y = -z + (old_x + old_y) * sin(ANGLE);
}
