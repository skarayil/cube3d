/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:41:16 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/10 15:41:17 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>

static bool	ft_is_walkable(t_data *data, double x, double y)
{
	char	c;
	int		map_x;
	int		map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || map_x >= data->map.grid.width
		|| map_y >= data->map.grid.height)
		return (false);
	c = data->map.grid.data[map_y][map_x];
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

static void	ft_move_forward_back(t_data *data)
{
	double	nx;
	double	ny;

	if (data->keys[KEY_W])
	{
		nx = data->player.pos.x + data->player.dir.x * MOVE_SPEED;
		ny = data->player.pos.y + data->player.dir.y * MOVE_SPEED;
		if (ft_is_walkable(data, nx, data->player.pos.y))
			data->player.pos.x = nx;
		if (ft_is_walkable(data, data->player.pos.x, ny))
			data->player.pos.y = ny;
	}
	if (data->keys[KEY_S])
	{
		nx = data->player.pos.x - data->player.dir.x * MOVE_SPEED;
		ny = data->player.pos.y - data->player.dir.y * MOVE_SPEED;
		if (ft_is_walkable(data, nx, data->player.pos.y))
			data->player.pos.x = nx;
		if (ft_is_walkable(data, data->player.pos.x, ny))
			data->player.pos.y = ny;
	}
}

static void	ft_strafe_left_right(t_data *data)
{
	double	nx;
	double	ny;

	if (data->keys[KEY_D])
	{
		nx = data->player.pos.x - data->player.dir.y * MOVE_SPEED;
		ny = data->player.pos.y + data->player.dir.x * MOVE_SPEED;
		if (ft_is_walkable(data, nx, data->player.pos.y))
			data->player.pos.x = nx;
		if (ft_is_walkable(data, data->player.pos.x, ny))
			data->player.pos.y = ny;
	}
	if (data->keys[KEY_A])
	{
		nx = data->player.pos.x + data->player.dir.y * MOVE_SPEED;
		ny = data->player.pos.y - data->player.dir.x * MOVE_SPEED;
		if (ft_is_walkable(data, nx, data->player.pos.y))
			data->player.pos.x = nx;
		if (ft_is_walkable(data, data->player.pos.x, ny))
			data->player.pos.y = ny;
	}
}

static void	ft_rotate(t_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(rot_speed)
		- data->player.dir.y * sin(rot_speed);
	data->player.dir.y = old_dir_x * sin(rot_speed) + data->player.dir.y
		* cos(rot_speed);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(rot_speed)
		- data->player.plane.y * sin(rot_speed);
	data->player.plane.y = old_plane_x * sin(rot_speed) + data->player.plane.y
		* cos(rot_speed);
}

void	ft_update_movement(t_data *data)
{
	ft_move_forward_back(data);
	ft_strafe_left_right(data);
	if (data->keys[KEY_RIGHT])
		ft_rotate(data, ROT_SPEED);
	if (data->keys[KEY_LEFT])
		ft_rotate(data, -ROT_SPEED);
}
