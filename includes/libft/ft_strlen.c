#include <stddef.h>

int	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (*s++)
		index++;
	return (index);
}
