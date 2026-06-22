/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:11:31 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/22 19:13:23 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../includes/cube3d/map.h"
#include <stdbool.h>

bool	ft_read_map(char *file, char ***lines);
bool	ft_texture_line(char *line)
{
	if (!line)
		return (false);
	if ((line[0] == 'N') && (line[1] == 'O'))
		return (true);
	else if ((line[0] == 'S') && (line[1] == 'O'))
		return (true);
	else if ((line[0] == 'W') && (line[1] == 'E'))
		return (true);
	else if ((line[0] == 'E') && (line[1] == 'A'))
		return (true);
	return (false);
}

bool	ft_color_line(char *line)
{
	if (!line)
		return (false);
	if ((line[0] == 'F') && (line[1] == ' '))
		return (true);
	else if ((line[0] == 'C') && (line[1] == ' '))
		return (true);
	return (false);
}

#include <stdio.h>

bool	ft_parse_file(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (ft_texture_line(lines[i]))
			printf("TEXTURE\n");
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
	char **lines;
	(void)ac;

	if (!ft_read_map(av[1], &lines))
		return (1);

	ft_parse_file(lines);
}