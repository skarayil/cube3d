#include "../parsing.h"

static void	ft_set_north(t_player *p)
{
	p->dir.x = 0;
	p->dir.y = -1;
	p->plane.x = 0.66;
	p->plane.y = 0;
}

static void	ft_set_south(t_player *p)
{
	p->dir.x = 0;
	p->dir.y = 1;
	p->plane.x = -0.66;
	p->plane.y = 0;
}

static void	ft_set_east(t_player *p)
{
	p->dir.x = 1;
	p->dir.y = 0;
	p->plane.x = 0;
	p->plane.y = 0.66;
}

static void	ft_set_west(t_player *p)
{
	p->dir.x = -1;
	p->dir.y = 0;
	p->plane.x = 0;
	p->plane.y = -0.66;
}

void	ft_set_player_dir(char c, t_player *p)
{
	if (c == 'N')
		ft_set_north(p);
	else if (c == 'S')
		ft_set_south(p);
	else if (c == 'E')
		ft_set_east(p);
	else if (c == 'W')
		ft_set_west(p);
}
