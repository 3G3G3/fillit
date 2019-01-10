#include "libft.h"

void	ft_strtabdel(char ***tab)
{
	size_t		i;

	i = 0;
	if (!tab || !*tab)
		return ;
	while ((*tab)[i][0] != '\0')
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}
