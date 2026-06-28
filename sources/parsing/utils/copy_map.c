/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:41:46 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 15:19:26 by skarayil         ###   ########.fr       */
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
		if ((int)ft_strlen(lines[i]) > max)
			max = ft_strlen(lines[i]);
		i++;
	}
	return (max);
}

bool	ft_copy_map(char **lines, int start, t_map *map)
{
	int	i;

	i = 0;
	map->grid.height = ft_map_height(lines, start);
	map->grid.width = ft_map_width(lines, start);
	map->grid.data = malloc(sizeof(char *) * (map->grid.height + 1));
	if (!map->grid.data)
		return (false);
	while (i < map->grid.height)
	{
		map->grid.data[i] = ft_strdup(lines[start + i]);
		if (!map->grid.data[i])
			return (false);
		i++;
	}
	map->grid.data[i] = NULL;
	return (true);
}