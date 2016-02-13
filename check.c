#include "fillit.h"

int	counttetri(char *tetri, int j)
{
	int	nbr;

	nbr = 0;
	if (j > 4)
	{
		if (tetri[j-5] == '#')
			nbr++;
	}
	if (j%5 != 0)
	{
		if (tetri[j-1] == '#')
			nbr++;
	}
	if (j%5 < 3)
	{
		if (tetri[j+1] == '#')
			nbr++;
	}
	if (j < 15)
	{
		if (tetri[j+5] == '#')
			nbr++;
	}
	return (nbr);
}

int	checktab(int *tab)
{
	if (tab[0] == 0 || tab[1] == 0 || tab[2] == 0 || tab[3] == 0)
		return (0);
	if ((tab[0] + tab[1] + tab[2] + tab[3]) < 6)
		return (0);
	return (1);
}

int	newtab(int *tab)
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	return (1);
}

int	check(char *tetri)
{
	int	i;
	int	j;
	int	*tab;
	int	count;

	tab = malloc(sizeof(int) * 4);
	newtab(tab);
	j = 0;
	count = 0;
	i = 0;
	while (j < 20)
	{
		if (tetri[j] == '#' && i <= 3)
			tab[i++] = counttetri(tetri, j);
		else if (tetri[j] == '\n')
			count++;
		else if (tetri[j] != '.')
			j = 54;
		j++;
	}
	if (tetri[4] != '\n' || tetri[9] != '\n' || tetri[14] != '\n'
			|| tetri[19] != '\n' || !(checktab(tab)))
		j = 54;	
	if (ft_strlen(tetri) == 21)
	{
		if (tetri[20] != '\n')
			j = 54;
	}
	free(tab);
	if (j > 50)
		return (0);
	return (1);
}
