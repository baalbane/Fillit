/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:28:16 by baalbane          #+#    #+#             */
/*   Updated: 2016/05/20 13:06:05 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	inittab(char **tab, int len)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < len)
	{
		tab[j] = malloc(sizeof(char) * (len + 1));
		tab[j][len] = '\0';
		while (i < len)
			tab[j][i++] = '.';
		i = 0;
		j++;
	}
	return (0);
}

int	goprint(char **tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		free(tab[i++]);
	}
	free(tab);
	return (1);
}

int	printmap(t_list *start, int len)
{
	int		i;
	char	**tab;

	tab = malloc(sizeof(char*) * len);
	inittab(tab, len);
	i = 0;
	while (i >= 0)
	{
		tab[start->coord[1]][start->coord[0]] = 'A' + i;
		tab[start->coord[1] + start->point[0][1]][start->coord[0]
		+ start->point[0][0]] = 'A' + i;
		tab[start->coord[1] + start->point[1][1]][start->coord[0]
		+ start->point[1][0]] = 'A' + i;
		tab[start->coord[1] + start->point[2][1]][start->coord[0]
		+ start->point[2][0]] = 'A' + i;
		if (start->next)
			start = start->next;
		else
			i = -2;
		i++;
	}
	return (goprint(tab, len));
}
