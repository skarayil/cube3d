/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:44:21 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 16:07:39 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "map.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static bool	ft_fill_lines(int fd, char **lines)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines[i++] = line;
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	return (true);
}

bool	ft_read_map(char *file, char ***lines)
{
	int		fd;
	int		count;

	count = ft_count_lines(file);
	if (count <= 0)
		return (false);
	*lines = malloc(sizeof(char *) * (count + 1));
	if (!*lines)
		return (false);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(*lines);
		*lines = NULL;
		return (false);
	}
	ft_fill_lines(fd, *lines);
	close(fd);
	return (true);
}
