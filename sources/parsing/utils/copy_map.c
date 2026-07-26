#include "../parsing.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	ft_line_is_empty(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n' && *line != '\r')
			return (false);
		line++;
	}
	return (true);
}

static int	ft_map_height(char **lines, int start)
{
	int	i;
	int	last_non_empty;

	i = start;
	last_non_empty = start - 1;
	while (lines[i])
	{
		if (!ft_line_is_empty(lines[i]))
			last_non_empty = i;
		i++;
	}
	i = start;
	while (i <= last_non_empty)
	{
		if (ft_line_is_empty(lines[i]))
			return (-1);
		i++;
	}
	return (last_non_empty - start + 1);
}

static char	*ft_trim_newline(char *str)
{
	char	*trimmed;
	int		len;

	len = ft_strlen(str);
	trimmed = ft_strdup(str);
	if (!trimmed)
		return (NULL);
	while (len > 0 && (trimmed[len - 1] == '\n' || trimmed[len - 1] == '\r'))
	{
		trimmed[len - 1] = '\0';
		len--;
	}
	return (trimmed);
}

static void	ft_free_partial(char **dst, int count)
{
	while (count-- > 0)
		free(dst[count]);
	free(dst);
}

bool	ft_copy_map(char **lines, int start, t_map *map)
{
	int		i;
	char	**dst;

	map->grid.height = ft_map_height(lines, start);
	if (map->grid.height < 1)
		return (false);
	map->grid.data = malloc(sizeof(char *) * (map->grid.height + 1));
	if (!map->grid.data)
		return (false);
	i = 0;
	dst = map->grid.data;
	while (i < map->grid.height)
	{
		dst[i] = ft_trim_newline(lines[start + i]);
		if (!dst[i])
			return (ft_free_partial(dst, i), false);
		i++;
	}
	dst[i] = NULL;
	map->grid.width = 0;
	return (true);
}
