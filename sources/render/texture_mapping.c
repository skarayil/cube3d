#include "cube3d.h"
#include <math.h>

int	ft_get_tex_num(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (2);
		return (3);
	}
	if (ray->dir_y > 0)
		return (1);
	return (0);
}

static int	ft_get_tex_x(t_data *data, t_ray *ray, t_img *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = data->player.pos.y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = data->player.pos.x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if (ray->side == 0 && ray->dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	ft_draw_tex_line(t_data *data, t_ray *ray, int x, t_img *tex)
{
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		y;

	tex_x = ft_get_tex_x(data, ray, tex);
	step = 1.0 * tex->height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_H / 2.0 + ray->line_height / 2.0) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		ft_put_pixel(&data->buffer, x, y, ft_get_pixel(tex, tex_x, tex_y));
		y++;
	}
}
