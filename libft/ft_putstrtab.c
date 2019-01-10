#include "libft.h"

void	ft_putstrtab(char **str)
{
	size_t		i;

	if (!str)
		return ;
	i = 0;
	while (str[i] && str[i][0] != '\0')
	{
		ft_putendl(str[i]);
		i++;
	}
}
