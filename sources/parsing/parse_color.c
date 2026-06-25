/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:12:59 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/25 17:39:19 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d/map.h"
#include <stdbool.h>

static bool	ft_has_digit(char *str)
{
	int i = 0;
	while (str[i] && str[i] != ',' && str[i] != '\n')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (true);
		i++;
	}
	return (false);
}

static bool	has_two_commas(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count == 2);
}

static int	ft_atoi_local(char *str)
{
	int	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

static int	ft_get_red(char *line)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	return (ft_atoi_local(&line[i]));
}

static int	ft_get_green(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	if (line[i] == ',')
		i++;
	return (ft_atoi_local(&line[i]));
}

static int	ft_get_blue(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		if (comma == 2)
			return (ft_atoi_local(&line[i + 1]));
		i++;
	}
	return (-1);
}
static int	ft_rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static bool	ft_valid_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (false);
	if (g < 0 || g > 255)
		return (false);
	if (b < 0 || b > 255)
		return (false);
	return (true);
}

static bool	ft_valid_color_chars(char *line)
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

bool	ft_parse_color(char *line, t_map *map)
{
	int r;
	int g;
	int b;

	if (!has_two_commas(line))
		return (false);

	if (!ft_valid_color_chars(line))
		return (false);

	if (!ft_has_digit(line))
		return (false);
	r = ft_get_red(line);
	g = ft_get_green(line);
	b = ft_get_blue(line);

	if (!ft_valid_rgb(r, g, b))
		return (false);

	if (line[0] == 'F')
	{
		if (map->floor_rgb != -1)
			return (false);
		map->floor_rgb = ft_rgb_to_int(r, g, b);
	}
	else if (line[0] == 'C')
	{
		if (map->ceil_rgb != -1)
			return (false);
		map->ceil_rgb = ft_rgb_to_int(r, g, b);
	}
	else
		return (false);

	return (true);
}