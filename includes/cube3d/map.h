/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:49:49 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 16:48:47 by skarayil         ###   ########.fr       */
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
bool					ft_parse_texture(char *line, t_map *map);
bool					ft_parse_color(char *line, t_map *map);
bool					ft_texture_line(char *line);
bool					ft_color_line(char *line);
bool					ft_check_identifiers(t_map *map);
int						ft_find_map_start(char **lines);
bool					ft_copy_map(char **lines, int start, t_map *map);
bool					ft_check_map(t_map *map);
bool					ft_check_char(t_map *map);
bool					ft_check_player(t_map *map);
bool					ft_check_rectangular(t_map *map);
bool					ft_check_surrounding_walls(t_map *map);
bool					ft_find_player(t_map *map, t_player *player);
int						ft_get_red(char *line);
int						ft_get_green(char *line);
int						ft_get_blue(char *line);
bool					ft_error(char *msg);

#endif