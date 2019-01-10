#include "fillit.h"

static t_tetris		*ft_ttrsnew(char **piece, char c)
{
	t_tetris	*res;

	res = (t_tetris *)ft_memalloc(sizeof(*res));
	if (!res)
		return (NULL);
	if (!piece)
		res->piece = NULL;
	else
		res->piece = (char **)piece;
	res->symbol = c;
	res->put = 0;
	res->next = NULL;
	return (res);
}

static void			ft_ttrsadd_fifo(t_tetris **alst, t_tetris  *new)
{
	t_tetris		*t;

	if			(!alst || !new)
		return ;
	if (!alst || !(*alst))
		*alst = new;
	else
	{
		t = *alst;
		while (t->next)
			t = t->next;
		t->next = new;
	}
}

void		ft_putstrtab(char **tab)
{
	size_t		i;

	if (!tab)
		return ;
	i = 0;
	while (ft_strcmp(tab[i], "\0") != 0)
	{
		ft_putendl(tab[i]);
		i++;
	}
	return ;
}

t_tetris			*ft_read_piece_file(const int fd)
{
	char		symbol;
	char		*sep;
	char		**tmp_piece;
	t_tetris	*res;

	symbol = 'A';
	ft_putendl("a");
	tmp_piece = ft_get_piece(fd);
	if (tmp_piece == NULL)
		return (NULL);
	ft_putendl("b");
	ft_putstrtab(tmp_piece);
	res = ft_ttrsnew(tmp_piece, symbol);
	if (!res)
		return (NULL);
	ft_putendl("c");
	ft_strtabdel(&tmp_piece);
	symbol++;
	ft_putendl("d");
	if (get_next_line(fd, &sep) < 1 ||
			ft_strcmp(sep, "\n") != 0)
		return (NULL);
// attention à la fuite mémoire en cas de return NULL
	ft_putendl("dd");
	ft_strdel(&sep);
	ft_putendl("e");
	while ((tmp_piece = ft_get_piece(fd)) != NULL)
	{
		ft_putendl("f");
		ft_ttrsadd_fifo(&res, ft_ttrsnew(tmp_piece, symbol));
		ft_putendl("g");
		ft_strtabdel(&tmp_piece);
		symbol++;
		ft_putendl("h");
		if (get_next_line(fd, &sep) < 1 &&
				ft_strcmp(sep, "\n") != 0)
			return (NULL);
// attention à la fuite mémoire en cas de return NULL
		ft_strdel(&sep);
	}
	ft_putendl("i");
	return (res);
}
