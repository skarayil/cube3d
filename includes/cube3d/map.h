/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:49:49 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/25 21:42:34 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_texture
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_texture;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_texture	texture;
	int			floor_rgb;
	int			ceil_rgb;
}				t_map;

int				ft_get_red(char *line);
int				ft_get_green(char *line);
int				ft_get_blue(char *line);
bool			ft_read_map(char *file, char ***lines);
bool			ft_parse_texture(char *line, t_map *map);
bool			ft_parse_color(char *line, t_map *map);
bool			ft_check_identifiers(t_map *map);

#endif