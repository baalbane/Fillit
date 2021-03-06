/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:27:43 by baalbane          #+#    #+#             */
/*   Updated: 2016/05/20 13:46:29 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		i;
	t_list	*start;

	if (launchread(av, ac, &start) == -1)
	{
		free_all(start);
		return (0);
	}
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
