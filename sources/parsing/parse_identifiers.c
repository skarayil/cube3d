/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:11:31 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/22 17:28:30 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

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
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_texture_line("NO ./a.xpm"));
	printf("%d\n", ft_texture_line("SO ./a.xpm"));
	printf("%d\n", ft_texture_line("F 220,100,0"));
	printf("%d\n", ft_texture_line("11111"));
}

bool	parse_texture(char *line, t_map *map);