/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:26:11 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 14:48:17 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "img.h"
# include "map.h"
# include "player.h"

typedef struct s_data
{
	void *mlx_ptr;     // MLX bağlantı pointer'ı
	void *win_ptr;     // MLX pencere pointer'ı
	t_map map;         // Senin parsing verilerin
	t_player player;   // Oyuncu verileri
	t_img buffer;      // Ekrana basılacak ana görüntü
	t_img textures[4]; // Yüklenmiş 4 duvar dokusu (N, S, E, W)
}	t_data;

#endif
