/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:39:28 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/10 15:39:33 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdbool.h>

typedef struct s_player	t_player;

typedef struct s_texture_path
{
	char				*north;
	char				*south;
	char				*west;
	char				*east;
}						t_texture_path;

typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

typedef struct s_grid
{
	char				**data;
	int					width;
	int					height;
}						t_grid;

typedef struct s_map
{
	t_grid				grid;
	t_texture_path		texture;
	t_rgb				floor;
	t_rgb				ceiling;
}						t_map;

bool					ft_read_map(char *file, char ***lines);
bool					ft_parse_file(char **lines, t_map *map,
							t_player *player);
bool					ft_error(char *msg);

#endif