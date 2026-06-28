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

#include "map.h"
#include "player.h"
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
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (ft_is_player_char(grid[i][j]))
				count++;
			j++;
		}
		i++;
	}
	return (count == 1);
}

static void	ft_set_north(t_player *p)
{
	p->dir.x = 0;
	p->dir.y = -1;
	p->plane.x = 0.66;
	p->plane.y = 0;
}

static void	ft_set_south(t_player *p)
{
	p->dir.x = 0;
	p->dir.y = 1;
	p->plane.x = -0.66;
	p->plane.y = 0;
}

static void	ft_set_east(t_player *p)
{
	p->dir.x = 1;
	p->dir.y = 0;
	p->plane.x = 0;
	p->plane.y = 0.66;
}

static void	ft_set_west(t_player *p)
{
	p->dir.x = -1;
	p->dir.y = 0;
	p->plane.x = 0;
	p->plane.y = -0.66;
}

static void	ft_set_player_dir(char c, t_player *p)
{
	if (c == 'N')
		ft_set_north(p);
	else if (c == 'S')
		ft_set_south(p);
	else if (c == 'E')
		ft_set_east(p);
	else if (c == 'W')
		ft_set_west(p);
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

bool	ft_find_player(t_map *map, t_player *p)
{
	int		x;
	int		y;
	char	**grid;

	grid = map->grid.data;
	y = 0;
	while (grid[y])
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
