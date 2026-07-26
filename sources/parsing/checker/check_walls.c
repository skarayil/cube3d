#include "libft.h"
#include "../parsing.h"
#include <stdbool.h>

static bool	ft_is_walkable(char c)
{
	if (c == '0')
		return (true);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

static bool	ft_cell_at(t_map *map, int row, int col)
{
	int	row_len;

	if (row < 0 || row >= map->grid.height)
		return (false);
	row_len = ft_strlen(map->grid.data[row]);
	if (col < 0 || col >= row_len)
		return (false);
	if (map->grid.data[row][col] == ' ')
		return (false);
	return (true);
}

static bool	ft_check_cell_closed(t_map *map, int row, int col)
{
	if (!ft_cell_at(map, row - 1, col))
		return (false);
	if (!ft_cell_at(map, row + 1, col))
		return (false);
	if (!ft_cell_at(map, row, col - 1))
		return (false);
	if (!ft_cell_at(map, row, col + 1))
		return (false);
	return (true);
}

bool	ft_check_map_closed(t_map *map)
{
	int		row;
	int		col;
	char	**grid;

	grid = map->grid.data;
	row = 0;
	while (row < map->grid.height)
	{
		col = 0;
		while (grid[row][col])
		{
			if (ft_is_walkable(grid[row][col]))
			{
				if (!ft_check_cell_closed(map, row, col))
					return (false);
			}
			col++;
		}
		row++;
	}
	return (true);
}
