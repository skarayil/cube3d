/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:41:12 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/10 15:41:13 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_close_game(data);
	if (keycode >= 0 && keycode < 65536)
		data->keys[keycode] = true;
	return (0);
}

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < 65536)
		data->keys[keycode] = false;
	return (0);
}
