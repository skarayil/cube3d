/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:41:46 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 14:45:18 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

static int	ft_map_height(char **lines, int start)
{
	int	height;

	height = 0;
	while (lines[start + height])
		height++;
	return (height);
}

static int	ft_map_width(char **lines, int start)
{
	int	i;
	int	max;

	i = start;
	max = 0;
	while (lines[i])
	{
		if (ft_strlen(lines[i]) > max)
			max = ft_strlen(lines[i]);
		i++;
	}
	return (max);
}

bool	ft_copy_map(char **lines, int start, t_map *map)
{
	int	i;

	i = 0;
	map->height = ft_map_height(lines, start);
	map->width = ft_map_width(lines, start);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (false);
	while (i < map->height)
	{
		map->grid[i] = ft_strdup(lines[start + i]);
		if (!map->grid[i])
			return (false);
		i++;
	}
	map->grid[i] = NULL;
	return (true);
}
