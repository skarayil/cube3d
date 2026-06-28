/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:10 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 16:44:32 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include "player.h"
#include <stdbool.h>

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

static bool	ft_parse_identifiers(char **lines, t_map *map)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (ft_texture_line(lines[i]))
		{
			if (!ft_parse_texture(lines[i], map))
				return (ft_error("Invalid texture line"));
		}
		else if (ft_color_line(lines[i]))
		{
			if (!ft_parse_color(lines[i], map))
				return (ft_error("Invalid color line"));
		}
		i++;
	}
	return (true);
}

bool	ft_parse_file(char **lines, t_map *map, t_player *player)
{
	int	start;

	if (!ft_parse_identifiers(lines, map))
		return (false);
	if (!ft_check_identifiers(map))
		return (ft_error("Missing identifiers"));
	start = ft_find_map_start(lines);
	if (start == -1)
		return (ft_error("Map not found"));
	if (!ft_copy_map(lines, start, map))
		return (ft_error("Failed to copy map"));
	if (!ft_check_map(map))
		return (false);
	if (!ft_find_player(map, player))
		return (ft_error("Player not found"));
	return (true);
}
