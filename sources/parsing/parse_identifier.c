/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:22:48 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/26 01:23:36 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdbool.h>

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
