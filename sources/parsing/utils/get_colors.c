/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:42:08 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/10 15:42:09 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
#include "libft.h"

static char	*ft_skip_to_comma(char *line, int target_commas)
{
	int	commas;

	commas = 0;
	while (*line)
	{
		if (*line == ',')
		{
			commas++;
			if (commas == target_commas)
				return (line + 1);
		}
		line++;
	}
	return (NULL);
}

int	ft_extract_red(char *line)
{
	line += 1;
	while (*line == ' ')
		line++;
	return (ft_atoi(line));
}

int	ft_extract_green(char *line)
{
	char	*next;

	next = ft_skip_to_comma(line, 1);
	if (!next)
		return (-1);
	return (ft_atoi(next));
}

int	ft_extract_blue(char *line)
{
	char	*next;

	next = ft_skip_to_comma(line, 2);
	if (!next)
		return (-1);
	return (ft_atoi(next));
}
