/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:10:00 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 18:10:00 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "map.h"
# include "player.h"

/* Parser functions */
bool	ft_texture_line(char *line);
bool	ft_color_line(char *line);
bool	ft_parse_texture(char *line, t_map *map);
bool	ft_parse_color(char *line, t_map *map);

/* Parser utils */
bool	ft_copy_map(char **lines, int start, t_map *map);
int		ft_extract_red(char *line);
int		ft_extract_green(char *line);
int		ft_extract_blue(char *line);

/* Checker functions */
bool	ft_check_map(t_map *map);
bool	ft_check_map_chars(t_map *map);
bool	ft_check_map_closed(t_map *map);
bool	ft_check_player(t_map *map);
bool	ft_init_player(t_map *map, t_player *p);
void	ft_set_player_dir(char c, t_player *p);

#endif
