/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:10 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/23 12:07:11 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d/map.h"
#include <stdbool.h>
#include <stdio.h>

bool	ft_read_map(char *file, char ***lines);
bool	ft_parse_texture(char *line, t_map *map);

bool	ft_texture_line(char *line)
{
	if (!line)
		return (false);
	if ((line[0] == 'N' && line[1] == 'O') || (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E') || (line[0] == 'E'
			&& line[1] == 'A'))
		return (true);
	return (false);
}

bool	ft_color_line(char *line)
{
	if (!line)
		return (false);
	if ((line[0] == 'F' && line[1] == ' ') || (line[0] == 'C'
			&& line[1] == ' '))
		return (true);
	return (false);
}

bool	ft_parse_file(char **lines, t_map *map)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (ft_texture_line(lines[i]))
			ft_parse_texture(lines[i], map);
		else if (ft_color_line(lines[i]))
			printf("COLOR\n");
		else
			printf("OTHER\n");
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	char	**lines;
	t_map	map;

	(void)ac;
	map.texture.no = NULL;
	map.texture.so = NULL;
	map.texture.we = NULL;
	map.texture.ea = NULL;
	if (!ft_read_map(av[1], &lines))
		return (1);
	ft_parse_file(lines, &map);
	printf("NO = %s\n", map.texture.no);
	printf("SO = %s\n", map.texture.so);
	printf("WE = %s\n", map.texture.we);
	printf("EA = %s\n", map.texture.ea);
	return (0);
}
