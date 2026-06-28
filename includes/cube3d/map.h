/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:49:49 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 15:38:42 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdbool.h>
# include "player.h"

typedef struct s_texture_path
{
    char    *north;     // Kuzey duvarı (NO)
    char    *south;     // Güney duvarı (SO)
    char    *west;      // Batı duvarı (WE)
    char    *east;      // Doğu duvarı (EA)
} t_texture_path;

typedef struct s_rgb
{
    int     r;
    int     g;
    int     b;
} t_rgb;

typedef struct s_grid
{
    char    **data;     // 2D harita dizisi
    int     width;      // Genişlik
    int     height;     // Yükseklik
} t_grid;

typedef struct s_map
{
    t_grid          grid;       // Harita grid'i
    t_texture_path  texture;    // Texture yolları
    t_rgb           floor;      // Zemin rengi
    t_rgb           ceiling;    // Tavan rengi
} t_map;

// Parser fonksiyonları
bool	ft_read_map(char *file, char ***lines);
bool	ft_parse_file(char **lines, t_map *map, t_player *player);
bool	ft_parse_texture(char *line, t_map *map);
bool	ft_parse_color(char *line, t_map *map);
bool	ft_check_identifiers(t_map *map);
bool	ft_texture_line(char *line);
bool	ft_color_line(char *line);
int		ft_find_map_start(char **lines);
bool	ft_copy_map(char **lines, int start, t_map *map);
bool	ft_check_char(t_map *map);
bool	ft_check_player(t_map *map);
bool	ft_find_player(t_map *map, t_player *player);
bool	ft_check_map(t_map *map);

// Renk yardımcı fonksiyonları
int		ft_get_red(char *line);
int		ft_get_green(char *line);
int		ft_get_blue(char *line);

#endif