/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:19:42 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 15:19:15 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "player.h"
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
	while (map->grid.data[i])
	{
		j = 0;
		while (map->grid.data[i][j])
		{
			if (ft_is_player(map->grid.data[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (false);
	return (true);
}

bool	ft_find_player(t_map *map, t_player *player)
{
	int	y;
	int	x;
	char	c;

	y = 0;
	while (map->grid.data[y])
	{
		x = 0;
		while (map->grid.data[y][x])
		{
			c = map->grid.data[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				player->pos.x = (double)x + 0.5;
				player->pos.y = (double)y + 0.5;
				if (c == 'N')
				{
					player->dir.x = 0;
					player->dir.y = -1;
					player->plane.x = 0.66;
					player->plane.y = 0;
				}
				else if (c == 'S')
				{
					player->dir.x = 0;
					player->dir.y = 1;
					player->plane.x = -0.66;
					player->plane.y = 0;
				}
				else if (c == 'E')
				{
					player->dir.x = 1;
					player->dir.y = 0;
					player->plane.x = 0;
					player->plane.y = 0.66;
				}
				else if (c == 'W')
				{
					player->dir.x = -1;
					player->dir.y = 0;
					player->plane.x = 0;
					player->plane.y = -0.66;
				}
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}