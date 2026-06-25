/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:12:47 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/25 16:12:52 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d/map.h"
#include <stdbool.h>

bool	ft_check_identifiers(t_map *map)
{
	if (!map->texture.no)
		return (false);
	if (!map->texture.so)
		return (false);
	if (!map->texture.we)
		return (false);
	if (!map->texture.ea)
		return (false);
	if (map->floor_rgb == -1)
		return (false);
	if (map->ceil_rgb == -1)
		return (false);
	return (true);
}