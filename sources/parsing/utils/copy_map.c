/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:41:46 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 16:39:32 by skarayil         ###   ########.fr       */
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

static char	*ft_trim_newline(char *str)
{
	char	*trimmed;
	int		len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		trimmed = ft_strdup(str);
		if (!trimmed)
			return (NULL);
		trimmed[len - 1] = '\0';
		return (trimmed);
	}
	return (ft_strdup(str));
}

bool	ft_copy_map(char **lines, int start, t_map *map)
{
	int		i;
	char	**dst;

	map->grid.height = ft_map_height(lines, start);
	map->grid.data = malloc(sizeof(char *) * (map->grid.height + 1));
	if (!map->grid.data)
		return (false);
	i = 0;
	dst = map->grid.data;
	while (i < map->grid.height)
	{
		dst[i] = ft_trim_newline(lines[start + i]);
		if (!dst[i])
		{
			while (i-- > 0)
				free(dst[i]);
			free(dst);
			return (false);
		}
		i++;
	}
	dst[i] = NULL;
	map->grid.width = 0;
	return (true);
}
