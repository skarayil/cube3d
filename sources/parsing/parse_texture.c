/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:06 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/23 12:07:07 by skarayil         ###   ########.fr       */
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

bool	ft_parse_texture(char *line, t_map *map)
{
	char	*path;

	path = ft_strdup_local(ft_texture_path(line));
	if (!path)
		return (false);

	if (line[0] == 'N' && line[1] == 'O')
		map->texture.no = path;
	else if (line[0] == 'S' && line[1] == 'O')
		map->texture.so = path;
	else if (line[0] == 'W' && line[1] == 'E')
		map->texture.we = path;
	else if (line[0] == 'E' && line[1] == 'A')
		map->texture.ea = path;

	return (true);
}