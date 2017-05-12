/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:30:20 by juhallyn          #+#    #+#             */
/*   Updated: 2017/05/11 15:54:29 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/fillit.h"

int			ft_line(char **tetri)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (tetri[x][y] == '.')
	{
		y = 0;
		while (y < 3 && tetri[x][y] == '.')
			y++;
		if (tetri[x][y] == '.')
			x++;
	}
	return (x);
}

int			ft_column(char **tetri)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (tetri[x][y] == '.')
	{
		x = 0;
		while (x < 3 && tetri[x][y] == '.')
			x++;
		if (y < 3 && tetri[x][y] == '.')
			y++;
	}
	return (y);
}

t_coord		ft_xy(char **tetri, int line, int column)
{
	t_coord		coord;
	int			x;
	int			y;
	int			compt;

	x = 0;
	y = x;
	compt = 0;
	while (compt <= 3)
	{
		while (x < 4 && tetri[y][x] == '.')
			x++;
		if (x < 4 && tetri[y][x] != '.')
		{
			coord.y[compt] = y - line;
			coord.x[compt++] = x - column;
			x++;
		}
		if (x == 4)
		{
			y++;
			x = 0;
		}
	}
	return (coord);
}

int			size_map(int n_tetri)
{
	if (n_tetri == 1)
		return (2);
	if (n_tetri == 2)
		return (3);
	if (n_tetri >= 3 && n_tetri <= 4)
		return (4);
	if (n_tetri >= 5 && n_tetri <= 6)
		return (5);
	if (n_tetri >= 7 && n_tetri <= 9)
		return (6);
	if (n_tetri >= 10 && n_tetri <= 12)
		return (7);
	if (n_tetri >= 13 && n_tetri <= 16)
		return (8);
	if (n_tetri >= 17 && n_tetri <= 20)
		return (9);
	if (n_tetri >= 21 && n_tetri <= 25)
		return (10);
	if (n_tetri == 26)
		return (11);
	return (0);
}
