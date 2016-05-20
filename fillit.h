/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:17:21 by baalbane          #+#    #+#             */
/*   Updated: 2016/05/20 13:44:07 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_list
{
	int				*coord;
	int				**point;
	struct s_list	*next;
}					t_list;

int					ft_search(int **tab, int max, t_list *tetri, int j);
int					canbeplace(t_list *tetri, int max);
int					algo(t_list *start, t_list *actuel, int max);

int					reset(t_list *actuel, int nbr);
int					ft_strlen(char *str);
int					**taballoc(int size);
int					freetab(int **tab, int nbr);
int					getsquare(t_list *start);

int					ft_sqrt(int nbr);

int					free_list(t_list *lst);
int					free_all(t_list *lst);
t_list				*new_list();
void				init_list(t_list *lst);

int					launchread(char **av, int ac, t_list **start);
t_list				*goread(int fd, t_list **start);
int					fill_lst(t_list *new, char *tetri);

int					inittab(char **tab, int len);
int					printmap(t_list *start, int len);
int					goprint(char **tab, int len);

int					counttetri(char *tetri, int j);
int					checktab(int *tab);
int					newtab(int *tab);
int					check(char *tetri);
int					checkline(char *tetri, int *tab);

void				ft_putchar(char c);
void				ft_putstr(char *s);

#endif
