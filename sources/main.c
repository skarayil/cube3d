/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:37:36 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 16:42:25 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cube3d.h"
#include <stdio.h>
#include <stdlib.h>

static bool	ft_check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	if (file[len - 4] != '.' || file[len - 3] != 'c')
		return (false);
	if (file[len - 2] != 'u' || file[len - 1] != 'b')
		return (false);
	return (true);
}

static void	ft_init_map(t_map *map)
{
	map->floor.r = -1;
	map->floor.g = -1;
	map->floor.b = -1;
	map->ceiling.r = -1;
	map->ceiling.g = -1;
	map->ceiling.b = -1;
	map->texture.north = NULL;
	map->texture.south = NULL;
	map->texture.west = NULL;
	map->texture.east = NULL;
	map->grid.data = NULL;
	map->grid.width = 0;
	map->grid.height = 0;
}

static void	ft_free_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

static void	ft_free_map(t_map *map)
{
	int	i;

	free(map->texture.north);
	free(map->texture.south);
	free(map->texture.west);
	free(map->texture.east);
	i = 0;
	while (i < map->grid.height)
	{
		free(map->grid.data[i]);
		i++;
	}
	free(map->grid.data);
}

int	main(int ac, char **av)
{
	char		**lines;
	t_map		map;
	t_player	player;

	if (ac != 2)
		return (ft_error("Usage: ./cub3D <map.cub>"), 1);
	if (!ft_check_extension(av[1]))
		return (ft_error("Invalid file extension"), 1);
	ft_init_map(&map);
	if (!ft_read_map(av[1], &lines))
		return (ft_error("Failed to read map"), 1);
	if (!ft_parse_file(lines, &map, &player))
	{
		ft_free_lines(lines);
		ft_free_map(&map);
		return (1);
	}
	ft_print_data(&map, &player);
	ft_free_lines(lines);
	ft_free_map(&map);
	return (0);
}
