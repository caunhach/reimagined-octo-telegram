/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:50:44 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/27 19:31:00 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "fdf");
	fdf->img->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img,
			&fdf->img->bpp, &fdf->img->ll, &fdf->img->endian);
}

void	default_fdf(t_fdf *fdf)
{
	fdf->zoom = ft_max((WIN_W / fdf->map->w / 2), (WIN_H / fdf->map->h / 2));
	fdf->shift_x = WIN_W / 2;
	fdf->shift_y = (WIN_H - fdf->map->h * fdf->zoom) / 2;
	fdf->iso = 1;
	fdf->altitude = 1;
	fdf->rot_x = 0;
	fdf->rot_y = 0;
	fdf->rot_z = 0;
}

void	mlx_main(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		ft_error("Error : alloc fail");
	fdf->map = map;
	fdf->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!fdf->img)
	{
		free_fdf(fdf);
		ft_error("Error : alloc fail");
	}
	default_fdf(fdf);
	init_mlx(fdf);
	draw(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, deal_key, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, close_win, fdf);
	mlx_loop(fdf->mlx);
	free_all(fdf);
}
