#include "libft.h"
#include "../parsing.h"
#include <stdbool.h>

static bool	ft_is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	ft_check_map_chars(t_map *map)
{
	int		i;
	int		j;
	char	**grid;

	grid = map->grid.data;
	i = 0;
	while (i < map->grid.height)
	{
		j = 0;
		while (grid[i][j])
		{
			if (!ft_is_valid_map_char(grid[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	ft_set_map_dimensions(t_map *map)
{
	int	i;
	int	len;
	int	max;

	if (!map->grid.data || map->grid.height < 1)
		return (false);
	max = 0;
	i = 0;
	while (i < map->grid.height)
	{
		len = ft_strlen(map->grid.data[i]);
		if (len > max)
			max = len;
		i++;
	}
	map->grid.width = max;
	return (max > 0);
}

bool	ft_check_map(t_map *map)
{
	if (!map->grid.data)
		return (ft_error("Map grid is NULL"));
	if (!ft_set_map_dimensions(map))
		return (ft_error("Map is empty"));
	if (!ft_check_map_chars(map))
		return (ft_error("Map contains invalid characters"));
	if (!ft_check_map_closed(map))
		return (ft_error("Map is not closed by walls"));
	if (!ft_check_player(map))
		return (ft_error("Map must contain exactly one player"));
	return (true);
}
