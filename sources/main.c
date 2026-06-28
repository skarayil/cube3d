/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:37:36 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 14:38:14 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d/map.h"
#include "../../includes/libft/libft.h"
#include <stdbool.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**lines;
	t_map	map;
	int		start;

	(void)ac;
	map.floor_rgb = -1;
	map.ceil_rgb = -1;
	map.texture.no = NULL;
	map.texture.so = NULL;
	map.texture.we = NULL;
	map.texture.ea = NULL;
	if (!ft_read_map(av[1], &lines))
		return (1);
	if (!ft_parse_file(lines, &map))
	{
		printf("Parse Error\n");
		return (1);
	}
	start = ft_find_map_start(lines);
	if (start == -1)
		return (1);
	if (!ft_copy_map(lines, start, &map))
		return (1);
	if (!ft_check_player(&map))
	{
		printf("Player Error\n");
		return (1);
	}
	printf("NO = %s\n", map.texture.no);
	printf("SO = %s\n", map.texture.so);
	printf("WE = %s\n", map.texture.we);
	printf("EA = %s\n", map.texture.ea);
	printf("FLOOR = %d\n", map.floor_rgb);
	printf("CEIL = %d\n", map.ceil_rgb);
	printf("MAP\n");
	for (int i = 0; map.grid[i]; i++)
		printf("%s", map.grid[i]);
	return (0);
}
