#include "fillit.h"


t_list	*goread(int fd)
{
	t_list	*start;
	t_list	*new;
	t_list	*prev;
	char	*tetri;
	int	ret;
	int	i;

	start = new_list();
	tetri = malloc(sizeof(char) * (BUFF_SIZE + 1));
	ret = read(fd, tetri, BUFF_SIZE);
	tetri[ret] = '\0';
	if (check(tetri))
		fill_lst(start, NULL, tetri);
	prev = start;
	while (ret = read(fd, tetri, BUFF_SIZE))
	{
		tetri[ret] = '\0';
		new = new_list();
		prev->next = new;
		if (check(tetri))
			fill_lst(new, prev, tetri);
		else
		{
			//FREE
			return (0);
		}
		prev = new;
	}
	return (start);
}

int	fill_lst(t_list *new, t_list *prev, char *tetri)
{
	int	i;
	int	coord[2];
	int	j;

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

int	check(char *tetri)
{
	return (1);
}
