/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:17:08 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 15:19:04 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdbool.h>

static bool	ft_valid_char(char c)
{
	if (c == '0')
		return (true);
	if (c == '1')
		return (true);
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'W')
		return (true);
	if (c == ' ')
		return (true);
	if (c == '\n')
		return (true);
	return (false);
}

bool	ft_check_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid.data[i])
	{
		j = 0;
		while (map->grid.data[i][j])
		{
			if (!ft_valid_char(map->grid.data[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_check_map(t_map *map)
{
	if (!ft_check_char(map))
		return (false);
	if (!ft_check_player(map))
		return (false);
	return (true);
}