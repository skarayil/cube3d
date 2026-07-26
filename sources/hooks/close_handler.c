#include "cube3d.h"
#include <stdlib.h>

void	ft_free_map(t_map *map)
{
	int	i;

	free(map->texture.north);
	free(map->texture.south);
	free(map->texture.west);
	free(map->texture.east);
	i = 0;
	if (map->grid.data)
	{
		while (i < map->grid.height)
		{
			free(map->grid.data[i]);
			i++;
		}
		free(map->grid.data);
	}
}

int	ft_close_game(t_data *data)
{
	int	i;

	ft_free_map(&data->map);
	if (data->buffer.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->buffer.img_ptr);
	i = 0;
	while (i < 4)
	{
		if (data->textures[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->textures[i].img_ptr);
		i++;
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
