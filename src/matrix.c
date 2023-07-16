/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:37:50 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/27 18:22:15 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	get_min_max_z(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->h)
	{
		i = -1;
		while (++i < map->w)
		{
			if (map->z_matrix[j][i] < map->min_z)
				map->min_z = map->z_matrix[j][i];
			else if (map->z_matrix[j][i] > map->max_z)
				map->max_z = map->z_matrix[j][i];
		}
	}
}

void	convert_to_lower(char *s)
{
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
			*s += 'a' - 'A';
		s++;
	}
}

int	set_color(t_map *map, char *s)
{
	int	color;

	while (*s && (ft_isdigit(*s) || *s == '-' || *s == '+' || *s == ','))
		s++;
	if (*s++ == 'x')
	{
		convert_to_lower(s);
		color = ft_atoi_base(s, 16);
		map->iscolor = 1;
		return (color);
	}
	else
		return (WHITE);
}

static void	check_split(t_map *map, char **split, char *line)
{
	int		i;

	i = 0;
	if (!split)
	{
		free(line);
		free_map(map);
		ft_error("Error : alloc fail");
	}
	while (split[i])
	{
		if (!ft_isdigit(*split[i]) && !ft_issign(*split[i]))
			break ;
		i++;
	}
	if (i != map->w || !check_arg_map(*split))
	{
		free(line);
		free_map(map);
		free_split(split);
		ft_error("Error : map incomplete");
	}
}

void	fill_matrix(t_map *map, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	j = -1;
	while (++j < map->h)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		check_split(map, split, line);
		i = -1;
		while (++i < map->w)
		{
			map->z_matrix[j][i] = ft_atoi(split[i]);
			map->color[j][i] = set_color(map, split[i]);
		}
		free_split(split);
		free(line);
	}
}
