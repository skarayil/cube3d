/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:24:26 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/26 01:28:26 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static bool	ft_is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (true);
	return (false);
}

int	ft_find_map_start(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (ft_is_map_line(lines[i]))
			return (i);
		i++;
	}
	return (-1);
}
