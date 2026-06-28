/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:19:42 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 14:45:39 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdbool.h>

static bool	ft_is_player(char c)
{
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'W')
		return (true);
	return (false);
}

bool	ft_check_player(t_map *map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (ft_is_player(map->grid[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (false);
	return (true);
}
