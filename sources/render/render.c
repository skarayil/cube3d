#include "cube3d.h"

static void	ft_draw_ceiling(t_data *data, int ceiling_color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			ft_put_pixel(&data->buffer, x, y, ceiling_color);
			x++;
		}
		y++;
	}
}

static void	ft_draw_floor(t_data *data, int floor_color)
{
	int	x;
	int	y;

	y = WIN_H / 2;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			ft_put_pixel(&data->buffer, x, y, floor_color);
			x++;
		}
		y++;
	}
}

int	ft_render(t_data *data)
{
	int	ceiling;
	int	floor_c;

	ft_update_movement(data);
	ceiling = ft_rgb_to_hex(data->map.ceiling);
	floor_c = ft_rgb_to_hex(data->map.floor);
	ft_draw_ceiling(data, ceiling);
	ft_draw_floor(data, floor_c);
	ft_raycast(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->buffer.img_ptr, 0, 0);
	return (0);
}
