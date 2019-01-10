#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_tetris	*pieces;

	if (argc != 2)
	{
		ft_putendl("Vas-y toi! un seul argument");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < -1)
		return (-1);
	pieces = ft_read_piece_file(fd);
	close(fd);
	return (0);
}
