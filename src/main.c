/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:26:39 by caunhach          #+#    #+#             */
/*   Updated: 2023/06/27 00:01:53 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_arg_num(char c)
{
	return (ft_isdigit(c) || ft_issign(c));
}

int	check_arg_map(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!str[i] || str[i] == '\n')
		return (1);
	if (str[i] != ',')
		return (0);
	if (str[++i] != '0')
		return (0);
	if (str[++i] != 'x')
		return (0);
	while (str[++i] && str[i] != '\n')
	{
		if (!ft_strchr("0123456789abcdefABCDEF", str[i]))
			return (0);
	}
	if (str[i] == '\0' || str[i] == '\n')
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (argc != 2)
		ft_error("Error : Invalid arguments");
	create_map(&map, argv[1]);
	mlx_main(map);
}
