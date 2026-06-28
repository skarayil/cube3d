/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:10 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 14:44:47 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
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
