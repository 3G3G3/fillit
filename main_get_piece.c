#include "libft/libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	**piece;

	if (argc != 2)
		ft_putendl("Wesh! un unique argument!");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putendl("Wallah, pb dans la lecture.. :/");
			return (-1);
		}
		ft_putendl("a");
		piece = ft_get_piece(fd);
		ft_putendl("b");
		if (piece == NULL)
			ft_putendl("error");
		else
			ft_putstrtab(piece);
		ft_putendl("c");
		if (piece != NULL)
			ft_strtabclr(&piece);
		ft_putendl("d");
		close(fd);
	}
	return (0);
}
