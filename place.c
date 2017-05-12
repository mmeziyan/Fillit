/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:14:30 by juhallyn          #+#    #+#             */
/*   Updated: 2017/05/11 18:58:56 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/fillit.h"

int				x_y(t_coord tmp, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tmp.y[i] >= size)
			return ('x');
		if (tmp.x[i] >= size)
			return ('y');
		i++;
	}
	return (FALSE);
}

t_coord			down_right(t_coord *coord, int n)
{
	int a;
	int b;

	a = -1;
	b = coord->x[0];
	while (++a < 4)
	{
		if (b > coord->x[a])
			b = coord->x[a];
	}
	a = -1;
	while (n == 'x' && ++a < 4)
		coord->x[a]++;
	a = -1;
	while (n == 'y' && ++a < 4)
	{
		coord->x[a] -= b;
		coord->y[a]++;
	}
	return (*coord);
}

void			delete_tetri(t_coord coord, char **f_map)
{
	if (f_map[coord.y[0]][coord.x[0]])
		f_map[coord.y[0]][coord.x[0]] = '.';
	if (f_map[coord.y[1]][coord.x[1]])
		f_map[coord.y[1]][coord.x[1]] = '.';
	if (f_map[coord.y[2]][coord.x[2]])
		f_map[coord.y[2]][coord.x[2]] = '.';
	if (f_map[coord.y[3]][coord.x[3]])
		f_map[coord.y[3]][coord.x[3]] = '.';
}

int				place(int size, t_coord *coord, int n_tetri, char **f_map)
{
	static	int		i = 0;
	t_coord			tetri[1];

	if (i == n_tetri)
		return (TRUE);
	*tetri = coord[i];
	while (check(*tetri, f_map, size) != 'y')
	{
		while (check(*tetri, f_map, size) != 'x')
		{
			if (check_place(tetri, f_map) == TRUE && place_a_tetri(\
				tetri, f_map, i + 'A') == TRUE)
			{
				i++;
				if (place(size, coord, n_tetri, f_map) == TRUE)
					aff_tab(size, f_map);
				delete_tetri(*tetri, f_map);
				i--;
			}
			*tetri = down_right(tetri, 'x');
		}
		*tetri = down_right(tetri, 'y');
	}
	return (FALSE);
}

int				place_a_tetri(t_coord *coord, char **f_map, int c)
{
	f_map[coord->y[1]][coord->x[1]] = c;
	f_map[coord->y[2]][coord->x[2]] = c;
	f_map[coord->y[3]][coord->x[3]] = c;
	f_map[coord->y[0]][coord->x[0]] = c;
	return (TRUE);
}
