/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 20:42:05 by juhallyn          #+#    #+#             */
/*   Updated: 2017/05/11 17:25:40 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/fillit.h"

int		check_place(t_coord *coord, char **f_map)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i < 4)
	{
		if (f_map[coord->y[i]][coord->x[i]] == '.')
			n++;
		i++;
	}
	if (n == 4)
		return (TRUE);
	return (FALSE);
}

char	**new_map(int size)
{
	int		i;
	int		x;
	int		y;
	char	**f_map;

	i = -1;
	x = -1;
	f_map = (char**)malloc(sizeof(char*) * (size + 1));
	while (++i < size)
	{
		f_map[i] = (char*)malloc(sizeof(char) * (size + 1));
		f_map[i][size + 1] = '\0';
	}
	f_map[i] = NULL;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
			f_map[x][y] = '.';
	}
	return (f_map);
}

int		check(t_coord coord, char **f_map, int size)
{
	int i;
	int n;

	i = -1;
	n = 0;
	while (++i < 4)
	{
		if (coord.y[i] >= (size))
			return ('y');
	}
	i = -1;
	while (++i < 4)
	{
		if (coord.x[i] > (size))
			return ('x');
	}
	if (f_map[coord.y[0]][coord.x[0]] == '.' && f_map[coord.y[1]][coord.x[1]] \
			== '.' && f_map[coord.y[2]][coord.x[2]] == '.' && f_map[coord.y[3]]\
			[coord.x[3]] == '.')
		return (TRUE);
	return (FALSE);
}
