#include <stdlib.h>

char	*ft_strdup(char *s)
{
	int		index;
	char	*new_str;

	index = 0;
	while (s[index])
		index++;
	new_str = (char *)malloc(sizeof(char) * (index + 1));
	if (!new_str)
		return (NULL);
	index = 0;
	while (s[index])
	{
		new_str[index] = s[index];
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
