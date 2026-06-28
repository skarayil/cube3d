/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:19:42 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 16:47:19 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
#include <stdbool.h>

static bool	ft_is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	ft_check_player(t_map *map)
{
	int		count;
	char	**grid;
	int		i;
	int		j;

	count = 0;
	grid = map->grid.data;
	i = -1;
	while (++i < map->grid.height)
	{
		j = 0;
		while (grid[i][j])
		{
			if (ft_is_player_char(grid[i][j]))
				count++;
			j++;
		}
	}
	return (count == 1);
}

static bool	ft_set_player(t_map *map, t_player *p, int x, int y)
{
	char	c;

	c = map->grid.data[y][x];
	if (!ft_is_player_char(c))
		return (false);
	p->pos.x = (double)x + 0.5;
	p->pos.y = (double)y + 0.5;
	ft_set_player_dir(c, p);
	return (true);
}

bool	ft_init_player(t_map *map, t_player *p)
{
	int		x;
	int		y;
	char	**grid;

	grid = map->grid.data;
	y = 0;
	while (y < map->grid.height)
	{
		x = 0;
		while (grid[y][x])
		{
			if (ft_set_player(map, p, x, y))
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}
