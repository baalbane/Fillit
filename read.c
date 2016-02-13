#include "fillit.h"


t_list	*goread(int fd)
{
	t_list	*start;
	t_list	*new;
	t_list	*prev;
	char	*tetri;
	int	ret;
	int	i;
	int	saveret;

	saveret = 20;
	start = new_list();
	tetri = malloc(sizeof(char) * (BUFF_SIZE + 1));
	ret = read(fd, tetri, BUFF_SIZE);
	tetri[ret] = '\0';
	//printf("test01\n%s", tetri);
	if (check(tetri))
		fill_lst(start, NULL, tetri);
	else
	{
		return (NULL);
	}
	prev = start;
	while (ret = read(fd, tetri, BUFF_SIZE))
	{
		saveret = ret;
		tetri[ret] = '\0';
		//printf("test01\n%s\n", tetri);
		//tetri = malloc(sizeof(char) * (BUFF_SIZE + 1));
		new = new_list();
		prev->next = new;

	//	ret = read(fd, tetri, BUFF_SIZE);
	//	tetri[ret] = '\0';
		if (check(tetri))
			fill_lst(new, prev, tetri);
		else
		{
			//free
			return (NULL);
		}
		prev = new;
	}
	if(saveret != 20)
		return (NULL);
	return (start);
}

int	fill_lst(t_list *new, t_list *prev, char *tetri)
{
	int	i;
	int	coord[2];
	int	j;

	//printf("test00\n%s\n", tetri);
	j = 0;
	i = 0;
	//if (prev == NULL)
	//	new->id = 0;
	//else
	//	new->id = prev->id + 1;
	while (tetri[i] != '#')
		i++;
	coord[0] = i % 5;
	coord[1] = i / 5;
	//printf("\nkqejwrfbkajwerf\n
	//printf("\n==NEW TETRI==\n\nx: %d\ty: %d\ti: %d\n", coord[0], coord[1], i);
	while (j < 3 && i < 21)
	{
		i++;
		if (tetri[i] == '#')
		{
			//printf("%d\t%d for i: %d\n", ((i%5) - coord[0]), ((i/5) - coord[1]), i);
			
			new->point[j][0] = (i % 5) - coord[0];
			new->point[j][1] = (i / 5) - coord[1];
			j++;
		}
	}
	return (0);
}
