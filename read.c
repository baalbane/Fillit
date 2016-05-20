/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:36:51 by baalbane          #+#    #+#             */
/*   Updated: 2016/05/20 13:48:11 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		launchread(char **av, int ac, t_list **start)
{
	int fd;

	if (ac != 2)
	{
		ft_putstr("usage: fillit file\n");
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd >= 0 && (*start = goread(fd, start)))
		return (1);
	ft_putstr("error\n");
	return (-1);
}

t_list	*goread(int fd, t_list **start)
{
	t_list	*new;
	t_list	*prev;
	char	tetri[BUFF_SIZE + 1];
	int		ret[2];

	ret[1] = 20;
	prev = NULL;
	while ((ret[0] = read(fd, tetri, BUFF_SIZE)))
	{
		ret[1] = ret[0];
		tetri[ret[0]] = '\0';
		new = new_list();
		if (prev != NULL)
			prev->next = new;
		else
			*start = new;
		if (check(tetri))
			fill_lst(new, tetri);
		else
			return (NULL);
		prev = new;
	}
	if (ret[1] != 20)
		return (NULL);
	return (*start);
}

int		fill_lst(t_list *new, char *tetri)
{
	int		i;
	int		coord[2];
	int		j;

	j = 0;
	i = 0;
	while (tetri[i] != '#')
		i++;
	coord[0] = i % 5;
	coord[1] = i / 5;
	while (j < 3 && i < 21)
	{
		i++;
		if (tetri[i] == '#')
		{
			new->point[j][0] = (i % 5) - coord[0];
			new->point[j][1] = (i / 5) - coord[1];
			j++;
		}
	}
	return (0);
}
