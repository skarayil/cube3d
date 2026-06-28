/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:41:53 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 15:14:22 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"

int	ft_get_red(char *line)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	return (ft_atoi(&line[i]));
}

int	ft_get_green(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	if (line[i] == ',')
		i++;
	return (ft_atoi(&line[i]));
}

int	ft_get_blue(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		if (comma == 2)
			return (ft_atoi(&line[i + 1]));
		i++;
	}
	return (-1);
}
