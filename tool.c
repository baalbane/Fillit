/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:27:11 by baalbane          #+#    #+#             */
/*   Updated: 2016/05/20 13:48:19 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	getsquare(t_list *start)
{
	int	i;

	i = 1;
	while ((start = start->next))
		i++;
	if (i > 26)
		return (0);
	i = ft_sqrt(i * 4);
	return (i);
}

int	reset(t_list *actuel, int nbr)
{
	actuel->coord[0] = nbr;
	actuel->coord[1] = nbr;
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	**taballoc(int size)
{
	int	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int*) * (size + 1));
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
