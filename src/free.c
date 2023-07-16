/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 23:30:38 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/27 00:01:03 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	if (map->z_matrix)
	{
		while (++i < map->h)
		{
			if (map->z_matrix[i])
				free(map->z_matrix[i]);
		}
		free(map->z_matrix);
	}
	i = -1;
	if (map->color)
	{
		while (++i < map->h)
			if (map->color[i])
				free(map->color[i]);
		free(map->color);
	}
	free(map);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_fdf(t_fdf *fdf)
{
	free_map(fdf->map);
	if (fdf->img)
		free(fdf->img);
	free(fdf);
}

void	free_all(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	free_fdf(fdf);
}

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}
