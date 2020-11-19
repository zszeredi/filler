#include "libft.h"

char		*ft_delete_double_array(char **str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}