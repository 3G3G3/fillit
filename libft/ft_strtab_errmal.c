#include "libft.h"

void	ft_strtab_errmal(char ***str, size_t n)
{
	size_t		i;

	if (!str)
		return ;
	i = 0;
	while (i < n)
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
	*str = NULL;
}
