/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:19:35 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/27 01:21:40 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	parse_file(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		ft_error("file does not exit");
	}
	fill_matrix(map, fd);
	close(fd);
}

void	alloc_map(t_map *map)
{
	int	i;

	i = -1;
	map->z_matrix = (int **)malloc(map->h * sizeof(int *));
	map->color = (int **)malloc(map->h * sizeof(int *));
	if (!map->z_matrix || !map->color)
	{
		free_map(map);
		ft_error("Error : can not allocate map");
	}
	while (++i < map->h)
	{
		map->z_matrix[i] = (int *)malloc(map->w * sizeof(int));
		map->color[i] = (int *)malloc(map->w * sizeof(int));
		if (!map->z_matrix || !map->color)
		{
			free_map(map);
			ft_error("Error : can not allocate map");
		}
	}
}

int	get_width(t_map *map, char *line)
{
	int		w;
	char	**split;

	if (!line)
	{
		free_map(map);
		ft_error("Error : empty map");
	}
	split = ft_split(line, ' ');
	if (!split)
	{
		free_map(map);
		ft_error("Error : alloc fail");
	}
	w = -1;
	while (split[++w] && check_arg_num(*split[w]))
	{
		if (!check_arg_map(split[w]))
		{
			free_split(split);
			return (-1);
		}
	}
	free_split(split);
	return (w);
}

t_map	*init_map(char *file)
{
	int		fd;
	t_map	*map;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error : file does not exits");
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	map->w = get_width(map, line);
	map->h = 0;
	while (line)
	{
		map->h++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}

void	create_map(t_map **map, char *file)
{
	*map = init_map(file);
	if ((*map)->w == -1)
	{
		free_map(*map);
		ft_error("Error : incorrect map's arguments");
	}
	alloc_map(*map);
	parse_file(*map, file);
	get_min_max_z(*map);
}
