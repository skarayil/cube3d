/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:43:00 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/10 15:43:01 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>

static void	ft_print_info(t_map *map, t_player *p)
{
	printf("=== TEXTURES ===\n");
	printf("NO = %s\n", map->texture.north);
	printf("SO = %s\n", map->texture.south);
	printf("WE = %s\n", map->texture.west);
	printf("EA = %s\n", map->texture.east);
	printf("\n=== COLORS ===\n");
	printf("FLOOR = RGB(%d, %d, %d)\n", map->floor.r, map->floor.g,
		map->floor.b);
	printf("CEIL = RGB(%d, %d, %d)\n", map->ceiling.r, map->ceiling.g,
		map->ceiling.b);
	printf("\n=== PLAYER ===\n");
	printf("POS = (%.2f, %.2f)\n", p->pos.x, p->pos.y);
	printf("DIR = (%.2f, %.2f)\n", p->dir.x, p->dir.y);
	printf("PLANE = (%.2f, %.2f)\n", p->plane.x, p->plane.y);
}

void	ft_print_data(t_map *map, t_player *p)
{
	int	i;

	ft_print_info(map, p);
	printf("\n=== MAP (%dx%d) ===\n", map->grid.width, map->grid.height);
	i = 0;
	while (i < map->grid.height)
	{
		printf("%s\n", map->grid.data[i]);
		i++;
	}
}
