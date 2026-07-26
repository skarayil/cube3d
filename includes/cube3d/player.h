#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
}			t_player;

#endif