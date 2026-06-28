/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:26:11 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 16:41:27 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "img.h"
# include "map.h"
# include "player.h"

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_player	player;
	t_img		buffer;
	t_img		textures[4];
}				t_data;

#endif
