/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:19:07 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/28 14:33:15 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_delta(t_coord *start, t_coord *end,
	t_coord *delta, t_coord *sign)
{
	if (start->x > end->x)
	{
		delta->x = start->x - end->x;
		sign->x = -1;
	}
	else
	{
		delta->x = end->x - start->x;
		sign->x = 1;
	}
	if (start->y > end->y)
	{
		delta->y = start->y - end->y;
		sign->y = -1;
	}
	else
	{
		delta->y = end->y - start->y;
		sign->y = 1;
	}
}

void	bresenham(t_fdf *fdf, t_coord start, t_coord end)
{
	t_coord	pix;
	t_coord	delta;
	t_coord	sign;
	int		diff;
	int		tmp;

	init_delta(&start, &end, &delta, &sign);
	diff = delta.x - delta.y;
	pix = start;
	while (pix.x != end.x || pix.y != end.y)
	{
		img_pixel_put(fdf, pix.x, pix.y, get_color(pix, start, end, delta));
		tmp = diff * 2;
		if (tmp > -delta.y)
		{
			pix.x += sign.x;
			diff -= delta.y;
		}
		if (tmp < delta.x)
		{
			pix.y += sign.y;
			diff += delta.x;
		}
	}
}
