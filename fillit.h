#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	int		*coord;
	int		**point;
	int		id;
	struct s_list	*next;
}			t_list;

int	ft_search(int **tab, int max, int x, int y);
int	canbeplace(t_list *tetri, int max);
int	algo(t_list *start, t_list *actuel, int max);


int	reset(t_list *actuel, int nbr);
int	**taballoc(int size);
int	freetab(int **tab, int nbr);

int	free_list(t_list *lst);
t_list	*new_list();
void	init_list(t_list *lst);

t_list	*goread(int fd);
int	fill_lst(t_list *new, t_list *prev, char *tetri);
int	check(char *tetri);

#endif
