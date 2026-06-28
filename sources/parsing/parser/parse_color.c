/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:12:59 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 15:18:57 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdbool.h>

static int	ft_rgb_to_int(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

static bool	ft_valid_format(char *line)
{
	int		i;
	int		comma_count;
	bool	has_digit;

	i = 0;
	comma_count = 0;
	has_digit = false;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ',')
			comma_count++;
		else if (line[i] >= '0' && line[i] <= '9')
			has_digit = true;
		i++;
	}
	return (comma_count == 2 && has_digit);
}

static bool	ft_valid_chars(char *line)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	while (line[i] && line[i] != '\n')
	{
		if (!(line[i] >= '0' && line[i] <= '9') && line[i] != ','
			&& line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_set_color_value(char *line, t_map *map, int r, int g, int b)
{
	if (line[0] == 'F')
	{
		if (map->floor.r != -1 || map->floor.g != -1 || map->floor.b != -1)
			return (false);
		map->floor.r = r;
		map->floor.g = g;
		map->floor.b = b;
	}
	else if (line[0] == 'C')
	{
		if (map->ceiling.r != -1 || map->ceiling.g != -1 || map->ceiling.b != -1)
			return (false);
		map->ceiling.r = r;
		map->ceiling.g = g;
		map->ceiling.b = b;
	}
	else
		return (false);
	return (true);
}

bool	ft_parse_color(char *line, t_map *map)
{
	int	r;
	int	g;
	int	b;
	int	rgb_int;

	if (!ft_valid_format(line))
		return (false);
	if (!ft_valid_chars(line))
		return (false);
	r = ft_get_red(line);
	g = ft_get_green(line);
	b = ft_get_blue(line);
	rgb_int = ft_rgb_to_int(r, g, b);
	if (rgb_int == -1)
		return (false);
	return (ft_set_color_value(line, map, r, g, b));
}
