/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:45:30 by juhallyn          #+#    #+#             */
/*   Updated: 2017/05/11 18:59:32 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFF 2048
# define TRUE 0
# define FALSE 1

typedef struct	s_coord
{
	int	x[4];
	int	y[4];
}				t_coord;

char			***all_tetris(int nb_tetri, char **map);
char			**open_file(char *file);
int				count_tetri(char **map);

char			**malloc_tetri(void);
char			**send_a_tetri(char **map, char c);

char			**split_map(char *map);

void			aff_tab(int size, char **map);
void			error(char *err);

int				ft_check_map(char *map, int nb_map);
int				ft_testriminos(char *s);
int				check_arguments(int argc);

t_coord			*init_coord(char ***map, int nb_tetri, t_coord *coord);

char			**new_map(int size);
int				ft_line(char **tetri);
t_coord			ft_xy(char **tetri, int line, int column);
int				x_y(t_coord tmp, int size);
int				ft_column(char **tetri);
int				size_map(int n_tetri);

int				place(int size, t_coord *coord, int nb_tetri, char **f_map);
int				place_a_tetri(t_coord *coord, char **f_map, int c);

int				check_place(t_coord *coord, char **f_map);
int				check(t_coord coord, char **f_map, int size);
t_coord			down_right(t_coord *coord, int n);
void			delete_tetri(t_coord coord, char **f_map);

#endif
