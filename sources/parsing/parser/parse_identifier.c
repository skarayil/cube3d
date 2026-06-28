/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:22:48 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 16:07:55 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static bool	ft_is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static bool	ft_is_texture_id(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (true);
	if (line[0] == 'S' && line[1] == 'O')
		return (true);
	if (line[0] == 'W' && line[1] == 'E')
		return (true);
	if (line[0] == 'E' && line[1] == 'A')
		return (true);
	return (false);
}

bool	ft_texture_line(char *line)
{
	if (!line)
		return (false);
	if (!ft_is_texture_id(line))
		return (false);
	if (!ft_is_space(line[2]))
		return (false);
	return (true);
}

bool	ft_color_line(char *line)
{
	if (!line)
		return (false);
	if ((line[0] == 'F' && ft_is_space(line[1]))
		|| (line[0] == 'C' && ft_is_space(line[1])))
		return (true);
	return (false);
}
