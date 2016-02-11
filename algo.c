#include "fillit.h"

int	ft_search(int **tab, int max, int x, int y)
{
	int	i;

	i = 0;
	while (tab[i][0] != -20)
	{
		if ((tab[i][0] == x && tab[i][1] == y) || x >= max || y >= max || x < 0 || y < 0)
			return (0);
		i++;
	}
	tab[i][0] = x;
	tab[i][1] = y;
	return (1);
}


int	canbeplace(t_list *tetri, int max)
{
	int	**tab;
	int	i;

	i = 0;
	tab = taballoc(max*max);
	while (1)
	{
		if (tetri->coord[0] == 1000)
			return (1);
		if (!(ft_search(tab, max, tetri->coord[0], tetri->coord[1])))
			return (freetab(tab, 0));
		while (i < 3)
		{
			if (!(ft_search(tab, max, (tetri->coord[0] + tetri->point[i][0]), (tetri->coord[1] + tetri->point[i][1]))))
				return (freetab(tab, 0));
			i++;
		}
		if (tetri->next == NULL)
			return (freetab(tab, 1));
		tetri = tetri->next;
		i = 0;
	}
}


int	algo(t_list *start, t_list *actuel, int max)
{
	if (actuel->coord[0] == 1000)
		reset(actuel, 0);
	else
	{
		actuel->coord[0]++;
		if (actuel->coord[0] >= max)
		{
			actuel->coord[0] = 0;
			actuel->coord[1]++;
		}
		if (actuel->coord[1] >= max)
		{
			reset(actuel, 1000);
			return (0);
		}
	}
	if (canbeplace(start, max))
	{
		if (actuel->next == NULL)
			return (1);
		if (algo(start, actuel->next, max))
			return (1);
	}
	return (algo(start, actuel, max));
}
