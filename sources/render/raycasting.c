#include "cube3d.h"
#include <math.h>

static void	ft_init_ray_vars(t_data *data, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIN_W - 1;
	ray->dir_x = data->player.dir.x + data->player.plane.x * ray->camera_x;
	ray->dir_y = data->player.dir.y + data->player.plane.y * ray->camera_x;
	ray->map_x = (int)data->player.pos.x;
	ray->map_y = (int)data->player.pos.y;
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
}

static void	ft_init_step_dist(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.pos.x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.pos.x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.pos.y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.pos.y)
			* ray->delta_dist_y;
	}
}

static void	ft_perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map.grid.data[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static void	ft_calculate_line(t_data *data, t_ray *ray, int x)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(WIN_H / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
	ft_draw_tex_line(data, ray, x, &data->textures[ft_get_tex_num(ray)]);
}

void	ft_raycast(t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_W)
	{
		ft_init_ray_vars(data, &ray, x);
		ft_init_step_dist(data, &ray);
		ft_perform_dda(data, &ray);
		ft_calculate_line(data, &ray, x);
		x++;
	}
}
