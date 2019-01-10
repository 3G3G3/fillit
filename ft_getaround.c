#include "fillit.h"

char	ft_getabove(char **piece, int i, int j)
{
	if (j == 0)
		return (0);
	return (piece[j - 1][i]);
}

char	ft_getunder(char **piece, int i, int j)
{
	if (j == 3)
		return (0);
	return (piece[j + 1][i]);
}

char	ft_getright(char **piece, int i, int j)
{
	if (i == 3)
		return (0);
	return (piece[j][i + 1]);
}

char	ft_getleft(char **piece, int i, int j)
{
	if (i == 0)
		return (0);
	return (piece[j][i - 1]);
}
