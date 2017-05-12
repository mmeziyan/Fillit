/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:41:15 by juhallyn          #+#    #+#             */
/*   Updated: 2017/05/11 15:54:36 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/fillit.h"

char	**malloc_tetri(void)
{
	int		index;
	char	**tetri;

	index = -1;
	tetri = (char**)malloc(sizeof(char*) * 5);
	while (++index < 4)
	{
		tetri[index] = (char*)malloc(sizeof(char) * 5);
		tetri[index][5] = '\0';
	}
	tetri[index] = NULL;
	return (tetri);
}

char	**send_a_tetri(char **map, char c)
{
	int		x;
	int		y;
	char	**tetri;

	x = -1;
	tetri = malloc_tetri();
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			tetri[x][y] = map[x][y];
			if (tetri[x][y] == '#')
				tetri[x][y] = c;
		}
	}
	return (tetri);
}
