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
#include "map.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	char		**lines;
	t_map		map;
	t_player	player;
	int			i;

	if (ac != 2)
		return (printf("Usage: ./cub3D <map.cub>\n"), 1);
	map.floor.r = -1;
	map.floor.g = -1;
	map.floor.b = -1;
	map.ceiling.r = -1;
	map.ceiling.g = -1;
	map.ceiling.b = -1;
	map.texture.north = NULL;
	map.texture.south = NULL;
	map.texture.west = NULL;
	map.texture.east = NULL;
	map.grid.data = NULL;
	map.grid.width = 0;
	map.grid.height = 0;
	if (!ft_read_map(av[1], &lines))
		return (printf("Error: Failed to read map\n"), 1);
	if (!ft_parse_file(lines, &map, &player))
	{
		i = 0;
		while (lines[i])
			free(lines[i++]);
		free(lines);
		return (1);
	}
	printf("=== TEXTURES ===\n");
	printf("NO = %s\n", map.texture.north);
	printf("SO = %s\n", map.texture.south);
	printf("WE = %s\n", map.texture.west);
	printf("EA = %s\n", map.texture.east);
	printf("\n=== COLORS ===\n");
	printf("FLOOR = RGB(%d, %d, %d)\n", map.floor.r, map.floor.g, map.floor.b);
	printf("CEIL = RGB(%d, %d, %d)\n", map.ceiling.r, map.ceiling.g,
		map.ceiling.b);
	printf("\n=== PLAYER ===\n");
	printf("POS = (%.2f, %.2f)\n", player.pos.x, player.pos.y);
	printf("DIR = (%.2f, %.2f)\n", player.dir.x, player.dir.y);
	printf("PLANE = (%.2f, %.2f)\n", player.plane.x, player.plane.y);
	printf("\n=== MAP (%dx%d) ===\n", map.grid.width, map.grid.height);
	i = 0;
	while (i < map.grid.height)
	{
		printf("%s\n", map.grid.data[i]);
		i++;
	}
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
	if (map.texture.north)
		free(map.texture.north);
	if (map.texture.south)
		free(map.texture.south);
	if (map.texture.west)
		free(map.texture.west);
	if (map.texture.east)
		free(map.texture.east);
	i = 0;
	while (i < map.grid.height)
	{
		if (map.grid.data[i])
			free(map.grid.data[i]);
		i++;
	}
	if (map.grid.data)
		free(map.grid.data);
	return (0);
}
