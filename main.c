#include "fillit.h"

int	main(int ac, char **av)
{
	int	fd;
	int	i;
	t_list	*start;

	i = 3;
	fd = open(av[1], O_RDONLY);
	start = goread(fd);

	while (!(algo(start, start, i)))
		i++;
	printmap(start, i);
	
	free_all(start);	
	return (0);
}
