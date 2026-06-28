/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:10 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 15:24:30 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include "player.h"
#include <stdbool.h>
#include <stdio.h>

bool	ft_check_identifiers(t_map *map)
{
	if (!map->texture.north)
		return (false);
	if (!map->texture.south)
		return (false);
	if (!map->texture.west)
		return (false);
	if (!map->texture.east)
		return (false);
	if (map->floor.r == -1 || map->floor.g == -1 || map->floor.b == -1)
		return (false);
	if (map->ceiling.r == -1 || map->ceiling.g == -1 || map->ceiling.b == -1)
		return (false);
	return (true);
}

bool	ft_parse_file(char **lines, t_map *map, t_player *player)
{
	int	i;

	i = 0;
	printf("=== PARSING START ===\n");
	
	while (lines[i])
	{
		printf("Line %d: %s", i, lines[i]);
		
		if (ft_texture_line(lines[i]))
		{
			printf("-> Texture line detected\n");
			if (!ft_parse_texture(lines[i], map))
			{
				printf("Error: Failed to parse texture at line %d\n", i);
				return (false);
			}
		}
		else if (ft_color_line(lines[i]))
		{
			printf("-> Color line detected\n");
			if (!ft_parse_color(lines[i], map))
			{
				printf("Error: Failed to parse color at line %d\n", i);
				return (false);
			}
		}
		i++;
	}
	
	printf("=== CHECKING IDENTIFIERS ===\n");
	if (!ft_check_identifiers(map))
	{
		printf("Error: Missing identifiers\n");
		printf("NO: %s\n", map->texture.north);
		printf("SO: %s\n", map->texture.south);
		printf("WE: %s\n", map->texture.west);
		printf("EA: %s\n", map->texture.east);
		printf("Floor: %d,%d,%d\n", map->floor.r, map->floor.g, map->floor.b);
		printf("Ceiling: %d,%d,%d\n", map->ceiling.r, map->ceiling.g, map->ceiling.b);
		return (false);
	}
	
	printf("=== FINDING MAP START ===\n");
	i = ft_find_map_start(lines);
	if (i == -1)
	{
		printf("Error: Map start not found\n");
		return (false);
	}
	printf("Map starts at line %d\n", i);
	
	printf("=== COPYING MAP ===\n");
	if (!ft_copy_map(lines, i, map))
	{
		printf("Error: Failed to copy map\n");
		return (false);
	}
	
	printf("=== CHECKING MAP ===\n");
	if (!ft_check_map(map))
	{
		printf("Error: Invalid map\n");
		return (false);
	}
	
	printf("=== FINDING PLAYER ===\n");
	if (!ft_find_player(map, player))
	{
		printf("Error: Player not found\n");
		return (false);
	}
	
	printf("=== PARSING SUCCESS ===\n");
	return (true);
}
