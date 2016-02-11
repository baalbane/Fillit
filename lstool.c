#include "fillit.h"

void	init_list(t_list *lst)
{
	int	i;

	lst->coord[0] = 1000;
	lst->coord[1] = 1000;
	i = -1;
	while (++i < 6)
		lst->point[i / 2][i % 2] = -1;
}

t_list	*new_list()
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
			return (NULL);
	new->coord = (int*)malloc(sizeof(int) * 2);
	new->point = (int**)malloc(sizeof(int*) * 3);
	new->point[0] = (int*)malloc(sizeof(int) * 2);
	new->point[1] = (int*)malloc(sizeof(int) * 2);
	new->point[2] = (int*)malloc(sizeof(int) * 2);

	new->next = NULL;
	init_list(new);
	return (new);
}

int	free_list(t_list *lst)
{
	free(lst->coord);
	free(lst->point[2]);
	free(lst->point[1]);
	free(lst->point[0]);
	free(lst->point);
	free(lst);
	return (0);
}

int	free_all(t_list *lst)
{
	if (lst->next)
		free_all(lst->next);
	free_list(lst);
	return (0);
}
