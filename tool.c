#include "fillit.h"

int	reset(t_list *actuel, int nbr)
{
	actuel->coord[0] = nbr;
	actuel->coord[1] = nbr;
	return (1);
}

int	**taballoc(int size)
{
	int	**tab;
	int	i;
	//printf("|| launch tab malloc ||\n");

	i = 0;	
	tab = malloc(sizeof(int) * size + 1);
	while (i < size)
	{
		tab[i] = malloc(sizeof(int) * 2);
		tab[i][0] = -20;
		tab[i][1] = -20;
		i++;
	}
	tab[i] = malloc(sizeof(int) * 2);
	tab[i][0] = -40;
	tab[i][1] = -40;
	//printf("|| tab malloc success ||\n");
	return (tab);
}

int	freetab(int **tab, int nbr)
{
	int	i;

	i = 0;
	while (tab[i][0] != -40)
		free(tab[i++]);
	free(tab[i]);
	free(tab);
	return (nbr);
}
