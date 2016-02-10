#include "fillit.h"

int	main(int ac, char **av)
{
	int	fd;
	int	i;
	t_list	*start;

	i = 6;
	fd = open(av[1], O_RDONLY);
	start = goread(fd);

	while (!(algo(start, start, i)))
		i++;
	//printf("\n\n\n==%d==\nfor i = %d", algo(start, start, i), i);
	while(start->next != NULL)
	{
		printf("%d %d\n%d %d\n%d %d\n%d %d\n\n", start->coord[0], start->coord[1], start->point[0][0], start->point[0][1], start->point[1][0], start->point[1][1], start->point[2][0], start->point[2][1]);
		start = start->next;
	}	
	printf("%d %d\n%d %d\n%d %d\n%d %d\n\n", start->coord[0], start->coord[1], start->point[0][0], start->point[0][1], start->point[1][0], start->point[1][1], start->point[2][0], start->point[2][1]);

	
	return (0);
}
