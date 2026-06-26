/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:10 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/26 14:29:37 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d/map.h"
#include "../../includes/libft/libft.h"
#include <stdbool.h>
#include <stdio.h>

bool	ft_check_identifiers(t_map *map)
{
	if (!map->texture.no)
		return (false);
	if (!map->texture.so)
		return (false);
	if (!map->texture.we)
		return (false);
	if (!map->texture.ea)
		return (false);
	if (map->floor_rgb == -1)
		return (false);
	if (map->ceil_rgb == -1)
		return (false);
	return (true);
}

bool	ft_parse_file(char **lines, t_map *map)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (ft_texture_line(lines[i]))
		{
			if (!ft_parse_texture(lines[i], map))
				return (false);
		}
		else if (ft_color_line(lines[i]))
		{
			if (!ft_parse_color(lines[i], map))
				return (false);
		}
		else
			printf("OTHER\n");
		i++;
	}
	if (!ft_check_identifiers(map))
		return (false);
	return (true);
}
int main(int ac, char **av)
{
    char    **lines;
    t_map   map;
    int     start;

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