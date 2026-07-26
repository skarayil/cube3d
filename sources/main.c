#include "libft.h"
#include "cube3d.h"
#include <stdlib.h>

static bool	ft_check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	if (file[len - 4] != '.' || file[len - 3] != 'c')
		return (false);
	if (file[len - 2] != 'u' || file[len - 1] != 'b')
		return (false);
	return (true);
}

static void	ft_init_map(t_map *map)
{
	map->floor.r = -1;
	map->floor.g = -1;
	map->floor.b = -1;
	map->ceiling.r = -1;
	map->ceiling.g = -1;
	map->ceiling.b = -1;
	map->texture.north = NULL;
	map->texture.south = NULL;
	map->texture.west = NULL;
	map->texture.east = NULL;
	map->grid.data = NULL;
	map->grid.width = 0;
	map->grid.height = 0;
}

static bool	ft_init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (false);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "cub3D");
	if (!data->win_ptr)
		return (false);
	data->buffer.img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (!data->buffer.img_ptr)
		return (false);
	data->buffer.addr = mlx_get_data_addr(data->buffer.img_ptr,
			&data->buffer.bpp, &data->buffer.line_length,
			&data->buffer.endian);
	return (true);
}

static bool	init_all(t_data *data, char *file)
{
	char	**lines;

	ft_memset(data, 0, sizeof(t_data));
	ft_init_map(&data->map);
	if (!ft_read_map(file, &lines))
		return (ft_error("Failed to read map"));
	if (!ft_parse_file(lines, &data->map, &data->player))
	{
		ft_free_map(&data->map);
		ft_free_lines(lines);
		return (false);
	}
	ft_free_lines(lines);
	if (!ft_init_game(data))
	{
		ft_free_map(&data->map);
		return (ft_error("MLX initialization failed"));
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_error("Usage: ./cub3D <map.cub>"), 1);
	if (!ft_check_extension(av[1]))
		return (ft_error("Invalid file extension"), 1);
	if (!init_all(&data, av[1]))
		return (1);
	if (!ft_load_textures(&data))
		return (ft_close_game(&data), 1);
	mlx_hook(data.win_ptr, X_EVENT_KEY_PRESS, 1L << 0, ft_key_press, &data);
	mlx_hook(data.win_ptr, X_EVENT_KEY_RELEASE, 1L << 1, ft_key_release, &data);
	mlx_hook(data.win_ptr, X_EVENT_DESTROY, 0, ft_close_game, &data);
	mlx_loop_hook(data.mlx_ptr, ft_render, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
