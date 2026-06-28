/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:24:26 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 16:08:53 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdbool.h>

static bool	ft_is_map_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '1')
		return (true);
	return (false);
}

int	ft_find_map_start(char **lines)
{
	int	idx;

	idx = 0;
	while (lines[idx])
	{
		if (ft_is_map_line(lines[idx]))
			return (idx);
		idx++;
	}
	return (-1);
}
