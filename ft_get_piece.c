#include "fillit.h"

static int		ft_iscorr_char(char c)
{
	if (c == '.' || c == '#')
		return (1);
	return (0);
}

static int		ft_iscorr_line(char *line)
{
	size_t		i;

	if (!line || ft_strlen(line) != 4)
		return (0);
	i = 0;
	while (line[i] && ft_iscorr_char(line[i]) == 1)
		i++;
	if (i == 4 && line[i] == '\0')
		return (1);
	return (0);
}

static int		ft_iscorr_piece(char **piece)
{
	size_t		i;
	size_t		j;
	size_t		n_square;

	if (!piece)
		return (0);
	n_square = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (piece[j][i] == '#')
				n_square++;
			if (piece[j][i] == '#' &&
				ft_getabove(piece, i, j) != '#' &&
				ft_getunder(piece, i, j) != '#' &&
				ft_getright(piece, i, j) != '#' &&
				ft_getleft(piece, i, j) != '#')
				return (0);
			i++;
		}
		j++;
	}
	if (n_square != 4)
		return (0);
	return (1);
}

char			**ft_get_piece(const int fd)
{
	size_t		i;
	char		**piece;

	piece = (char **)malloc(sizeof(char *) * 5);
	if (!piece)
		return (NULL);
	piece[4] = "\0";
	i = 0;
	while (i < 4 && get_next_line(fd, &(piece[i])) == 1 &&
			ft_iscorr_line(piece[i]) == 1)
		i++;
	if (i == 4 && ft_iscorr_piece(piece) == 1)
		return (piece);
	else
		ft_strtab_errmal(&piece, i);
	return (NULL);
}
