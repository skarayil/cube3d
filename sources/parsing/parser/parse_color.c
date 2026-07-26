#include "../parsing.h"
#include <stdbool.h>

static bool	ft_validate_part(char **line, bool expect_comma)
{
	int	digits;

	while (**line == ' ' || **line == '\t')
		(*line)++;
	digits = 0;
	while (**line >= '0' && **line <= '9')
	{
		digits++;
		(*line)++;
	}
	if (digits == 0)
		return (false);
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if (expect_comma && **line != ',')
		return (false);
	if (expect_comma)
		(*line)++;
	else if (**line != '\0' && **line != '\n' && **line != '\r')
		return (false);
	return (true);
}

static bool	ft_validate_rgb(char *line)
{
	line++;
	if (*line != ' ' && *line != '\t')
		return (false);
	if (!ft_validate_part(&line, true))
		return (false);
	if (!ft_validate_part(&line, true))
		return (false);
	if (!ft_validate_part(&line, false))
		return (false);
	return (true);
}

static bool	ft_set_color_value(char *line, t_map *map, t_rgb color)
{
	if (line[0] == 'F')
	{
		if (map->floor.r != -1 || map->floor.g != -1 || map->floor.b != -1)
			return (false);
		map->floor = color;
	}
	else if (line[0] == 'C')
	{
		if (map->ceiling.r != -1 || map->ceiling.g != -1
			|| map->ceiling.b != -1)
			return (false);
		map->ceiling = color;
	}
	else
		return (false);
	return (true);
}

bool	ft_parse_color(char *line, t_map *map)
{
	int		r;
	int		g;
	int		b;
	t_rgb	color;

	if (!ft_validate_rgb(line))
		return (false);
	r = ft_extract_red(line);
	g = ft_extract_green(line);
	b = ft_extract_blue(line);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (false);
	color.r = r;
	color.g = g;
	color.b = b;
	return (ft_set_color_value(line, map, color));
}
