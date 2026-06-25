/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:06 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/25 23:31:38 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d/map.h"
#include "../../includes/libft/libft.h"
#include <stdbool.h>
#include <stdlib.h>

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

	len = ft_strlen(path);
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

static bool	ft_set_texture_value(char *line, t_map *map, char *path)
{
	char	**textures[4];
	char	*keys[4];
	int		i;

	textures[0] = &map->texture.no;
	textures[1] = &map->texture.so;
	textures[2] = &map->texture.we;
	textures[3] = &map->texture.ea;
	keys[0] = "NO";
	keys[1] = "SO";
	keys[2] = "WE";
	keys[3] = "EA";
	i = 0;
	while (i < 4)
	{
		if (line[0] == keys[i][0] && line[1] == keys[i][1])
		{
			if (*textures[i])
				return (false);
			*textures[i] = path;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_parse_texture(char *line, t_map *map)
{
	char	*path;

	path = ft_strdup(ft_texture_path(line));
	if (!path)
		return (false);
	if (!path[0] || path[0] == '\n')
	{
		free(path);
		return (false);
	}
	if (path[ft_strlen(path) - 1] == '\n')
		path[ft_strlen(path) - 1] = '\0';
	if (!ft_set_texture_value(line, map, path))
	{
		free(path);
		return (false);
	}
	if (!ft_is_xpm(path))
	{
		free(path);
		return (false);
	}
	return (true);
}
