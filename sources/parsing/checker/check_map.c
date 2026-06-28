/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:17:08 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 16:45:11 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include <stdbool.h>
#include <stdio.h>

static bool	ft_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	if (c == ' ' || c == '\n')
		return (true);
	return (false);
}

bool	ft_check_char(t_map *map)
{
	int		i;
	int		j;
	char	**grid;

	grid = map->grid.data;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (!ft_valid_char(grid[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_check_rectangular(t_map *map)
{
	int		i;
	int		len;
	char	**grid;

	grid = map->grid.data;
	if (!grid || map->grid.height < 1)
		return (false);
	len = ft_strlen(grid[0]);
	i = 1;
	while (i < map->grid.height)
	{
		if ((int)ft_strlen(grid[i]) != len)
		{
			printf("Line %d length: %d, expected: %d\n", i,
				(int)ft_strlen(grid[i]), len);
			return (false);
		}
		i++;
	}
	map->grid.width = len;
	return (true);
}

static bool	ft_check_row_walls(char *row, int len)
{
	if (len < 1)
		return (false);
	if (row[0] != '1' || row[len - 1] != '1')
		return (false);
	return (true);
}

bool	ft_check_surrounding_walls(t_map *map)
{
	int		i;
	char	**grid;

	grid = map->grid.data;
	if (map->grid.height < 3 || map->grid.width < 3)
		return (false);
	i = 0;
	while (i < map->grid.width)
	{
		if (grid[0][i] != '1' || grid[map->grid.height - 1][i] != '1')
			return (false);
		i++;
	}
	i = 1;
	while (i < map->grid.height - 1)
	{
		if (!ft_check_row_walls(grid[i], map->grid.width))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_map(t_map *map)
{
	if (!map->grid.data)
		return (ft_error("Map grid is NULL"));
	if (!ft_check_rectangular(map))
		return (ft_error("Map is not rectangular"));
	if (!ft_check_char(map))
		return (ft_error("Map contains invalid characters"));
	if (!ft_check_surrounding_walls(map))
		return (ft_error("Map is not surrounded by walls"));
	if (!ft_check_player(map))
		return (ft_error("Map does not contain exactly one player"));
	return (true);
}
