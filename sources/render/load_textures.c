#include "cube3d.h"

static bool	ft_load_single(t_data *data, t_img *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&tex->width, &tex->height);
	if (!tex->img_ptr)
		return (false);
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp,
			&tex->line_length, &tex->endian);
	return (true);
}

bool	ft_load_textures(t_data *data)
{
	if (!ft_load_single(data, &data->textures[0], data->map.texture.north))
		return (ft_error("Failed to load North texture"), false);
	if (!ft_load_single(data, &data->textures[1], data->map.texture.south))
		return (ft_error("Failed to load South texture"), false);
	if (!ft_load_single(data, &data->textures[2], data->map.texture.east))
		return (ft_error("Failed to load East texture"), false);
	if (!ft_load_single(data, &data->textures[3], data->map.texture.west))
		return (ft_error("Failed to load West texture"), false);
	return (true);
}
