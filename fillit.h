#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct			s_tetris
{
	char				**piece;
	char				symbol;
	int					put;
	struct s_tetris		*next;
}						t_tetris;

char					ft_getabove(char **piece, int i, int j);

char					ft_getunder(char **piece, int i, int j);

char					ft_getright(char **piece, int i, int j);

char					ft_getleft(char **piece, int i, int j);

char	**ft_get_piece(const int fd);

t_tetris	*ft_read_piece_file(const int fd);
#endif
