/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:00:51 by baalbane          #+#    #+#             */
/*   Updated: 2016/05/18 18:36:37 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	counttetri(char *tetri, int j)
{
	int	nbr;

	nbr = 0;
	if (j > 4 && tetri[j - 5] == '#')
		nbr++;
	if (j % 5 != 0 && tetri[j - 1] == '#')
		nbr++;
	if (j % 5 < 3 && tetri[j + 1] == '#')
		nbr++;
	if (j < 15 && tetri[j + 5] == '#')
		nbr++;
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

int	checkline(char *tetri, int *tab)
{
	if (tetri[4] != '\n' || tetri[9] != '\n' || tetri[14] != '\n'
	|| tetri[19] != '\n' || !(checktab(tab))
	|| (ft_strlen(tetri) == 21 && tetri[20] != '\n'))
	{
		free(tab);
		return (0);
	}
	free(tab);
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
		else if (tetri[j] == '#' && i > 3)
			j = 53;
		else if (tetri[j] == '\n')
			count++;
		else if (tetri[j] != '.')
			j = 53;
		j++;
	}
	if (j > 53 || !checkline(tetri, tab))
		return (0);
	return (1);
}
