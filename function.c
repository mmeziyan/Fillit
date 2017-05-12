/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:58:45 by juhallyn          #+#    #+#             */
/*   Updated: 2017/05/11 18:59:54 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/fillit.h"

void	error(char *err)
{
	ft_putendl(err);
	exit(1);
}

void	aff_tab(int size, char **map)
{
	int i;
	int y;

	i = -1;
	while (++i < size)
	{
		y = -1;
		while (++y != size)
			ft_putchar(map[i][y]);
		ft_putchar('\n');
	}
	exit(TRUE);
}

char	**split_map(char *map)
{
	char **map_split;

	map_split = ft_strsplit(map, '\n');
	return (map_split);
}

int		check_arguments(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage : ./fillit the_file\n");
		exit(FALSE);
	}
	return (TRUE);
}
