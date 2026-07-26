#include "libft.h"
#include "map.h"
#include "player.h"
#include "../parsing.h"
#include <stdbool.h>

static bool	ft_is_empty_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n' && *line != '\r')
			return (false);
		line++;
	}
	return (true);
}

static bool	ft_check_identifiers(t_map *map)
{
	if (!map->texture.north || !map->texture.south)
		return (false);
	if (!map->texture.west || !map->texture.east)
		return (false);
	if (map->floor.r == -1 || map->floor.g == -1 || map->floor.b == -1)
		return (false);
	if (map->ceiling.r == -1 || map->ceiling.g == -1)
		return (false);
	if (map->ceiling.b == -1)
		return (false);
	return (true);
}

static bool	ft_parse_line(char *line, t_map *map)
{
	if (ft_texture_line(line))
	{
		if (!ft_parse_texture(line, map))
			return (ft_error("Invalid texture line"));
	}
	else if (ft_color_line(line))
	{
		if (!ft_parse_color(line, map))
			return (ft_error("Invalid color line"));
	}
	else if (!ft_is_empty_line(line))
		return (ft_error("Unknown identifier"));
	return (true);
}

static bool	ft_parse_identifiers(char **lines, t_map *map, int *end)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (!ft_is_empty_line(lines[i])
			&& !ft_texture_line(lines[i])
			&& !ft_color_line(lines[i]))
			break ;
		if (!ft_parse_line(lines[i], map))
			return (false);
		i++;
	}
	*end = i;
	return (true);
}

bool	ft_parse_file(char **lines, t_map *map, t_player *player)
{
	int	start;

	if (!ft_parse_identifiers(lines, map, &start))
		return (false);
	if (!ft_check_identifiers(map))
		return (ft_error("Missing identifiers"));
	if (start == 0 || !lines[start])
		return (ft_error("Map not found"));
	if (!ft_copy_map(lines, start, map))
		return (ft_error("Failed to copy map"));
	if (!ft_check_map(map))
		return (false);
	if (!ft_init_player(map, player))
		return (ft_error("Player not found"));
	return (true);
}
