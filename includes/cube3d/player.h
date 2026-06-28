/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:25:35 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 15:12:04 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_player
{
	t_vec2 pos;   // Pozisyon
	t_vec2 dir;   // Bakış yönü
	t_vec2 plane; // Kamera düzlemi
}			t_player;

#endif