/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:07:55 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/28 21:26:47 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_win(t_fdf *fdf)
{
	free_all(fdf);
	exit(0);
	return (0);
}

int	deal_key(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		close_win(fdf);
	if (key == KEY_W || key == KEY_A
		|| key == KEY_S || key == KEY_D)
		move(key, fdf);
	if (key == KEY_PLUS || key == KEY_MINUS)
		zoom(key, fdf);
	if (key == KEY_Z || key == KEY_X || key == KEY_C
		|| key == KEY_V || key == KEY_B || key == KEY_N)
		rot(key, fdf);
	if (key == KEY_UP || key == KEY_DOWN)
		altitude(key, fdf);
	if (key == KEY_P)
	{
		if (fdf->iso)
			fdf->iso = 0;
		else
			fdf->iso = 1;
	}
	if (key == KEY_R)
		default_fdf(fdf);
	draw(fdf);
	return (0);
}
