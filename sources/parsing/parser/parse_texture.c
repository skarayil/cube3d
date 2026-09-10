/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:41:53 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/10 15:48:29 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
#include "libft.h"
#include "map.h"
#include <stdbool.h>
#include <stdlib.h>

static char	*ft_extract_texture_path(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line + i);
}

static bool	ft_is_xpm(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (false);
	if (path[len - 4] != '.' || path[len - 3] != 'x')
		return (false);
	if (path[len - 2] != 'p' || path[len - 1] != 'm')
		return (false);
	return (true);
}

static bool	ft_set_texture_value(char *line, t_map *map, char *path)
{
	char	**dst;

	dst = NULL;
	if (line[0] == 'N' && line[1] == 'O')
		dst = &map->texture.north;
	else if (line[0] == 'S' && line[1] == 'O')
		dst = &map->texture.south;
	else if (line[0] == 'W' && line[1] == 'E')
		dst = &map->texture.west;
	else if (line[0] == 'E' && line[1] == 'A')
		dst = &map->texture.east;
	if (!dst || *dst)
		return (false);
	*dst = path;
	return (true);
}

static void	ft_trim_trailing_whitespace(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len
				- 1] == '\n' || str[len - 1] == '\r'))
	{
		str[len - 1] = '\0';
		len--;
	}
}

bool	ft_parse_texture(char *line, t_map *map)
{
	char	*raw;
	char	*path;

	raw = ft_extract_texture_path(line);
	if (!raw[0] || raw[0] == '\n' || raw[0] == '\r')
		return (false);
	path = ft_strdup(raw);
	if (!path)
		return (false);
	ft_trim_trailing_whitespace(path);
	if (!ft_is_xpm(path))
		return (free(path), false);
	if (!ft_set_texture_value(line, map, path))
		return (free(path), false);
	return (true);
}
