/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:39:07 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/10 15:39:10 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "img.h"
# include "map.h"
# include "mlx.h"
# include "player.h"

# define WIN_W 1280
# define WIN_H 720
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROY 17

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define MOVE_SPEED 0.03
# define ROT_SPEED 0.03

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_player	player;
	t_img		buffer;
	t_img		textures[4];
	bool		keys[65536];
}				t_data;

void			ft_print_data(t_map *map, t_player *player);
void			ft_free_map(t_map *map);
void			ft_free_lines(char **lines);
int				ft_close_game(t_data *data);
int				ft_key_press(int keycode, t_data *data);
int				ft_key_release(int keycode, t_data *data);
void			ft_update_movement(t_data *data);
int				ft_render(t_data *data);
void			ft_put_pixel(t_img *img, int x, int y, int color);
int				ft_get_pixel(t_img *img, int x, int y);
int				ft_rgb_to_hex(t_rgb color);
void			ft_raycast(t_data *data);
int				ft_get_tex_num(t_ray *ray);
void			ft_draw_tex_line(t_data *data, t_ray *ray, int x, t_img *tex);
bool			ft_load_textures(t_data *data);

#endif
