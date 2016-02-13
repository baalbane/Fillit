#include "fillit.h"

int	main(int ac, char **av)
{
	int	fd;
	int	i;
	t_list	*start;

	fd = open(av[1], O_RDONLY);
	if (!(start = goread(fd)))
		return (0);

	i = getsquare(start);
	
	if (i > 0)
	{
		while (!(algo(start, start, i)))
			i++;
		printmap(start, i);
	}
	
	free_all(start);	
	return (0);
}
