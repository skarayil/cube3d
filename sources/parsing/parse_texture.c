/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:06 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/25 17:38:00 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d/map.h"
#include <stdbool.h>
#include <stdlib.h>

static int	ft_strlen_local(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup_local(char *s)
{
	int		i;
	char	*copy;

	copy = malloc(ft_strlen_local(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	*ft_texture_path(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	return (&line[i]);
}

static bool	ft_is_xpm(char *path)
{
	int	len;

	len = ft_strlen_local(path);
	if (len < 4)
		return (false);
	if (path[len - 4] != '.')
		return (false);
	if (path[len - 3] != 'x')
		return (false);
	if (path[len - 2] != 'p')
		return (false);
	if (path[len - 1] != 'm')
		return (false);
	return (true);
}

bool	ft_parse_texture(char *line, t_map *map)
{
	char *path;

	path = ft_strdup_local(ft_texture_path(line));
	if (!path)
		return (false);

	if (!path[0] || path[0] == '\n')
		return (false);

	if (path[ft_strlen_local(path) - 1] == '\n')
		path[ft_strlen_local(path) - 1] = '\0';
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (map->texture.no)
			return (false);
		map->texture.no = path;
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (map->texture.so)
			return (false);
		map->texture.so = path;
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (map->texture.we)
			return (false);
		map->texture.we = path;
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		if (map->texture.ea)
			return (false);
		map->texture.ea = path;
	}
	else
		return (false);
	if (!ft_is_xpm(path))
		return (false);

	return (true);
}