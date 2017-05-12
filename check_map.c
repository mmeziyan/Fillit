/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:43:46 by juhallyn          #+#    #+#             */
/*   Updated: 2017/05/11 15:53:24 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/fillit.h"

int		ft_check_map(char *map, int nb_map)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = 0
	;
	if (!map || !*map || map[4] != '\n' || map[9] != '\n' || map[14] != '\n' \
		|| map[19] != '\n' || nb_map > 26)
		error("error");
	while (++i <= 19)
	{
		if (map[i] != '\n' && map[i] != '.' && map[i] != '#')
			return (FALSE);
		if (map[i] == '\n')
			j++;
		if (map[i] == '#')
			k++;
	}
	if (j == 4 && k == 4 && map[19] == '\n' && map[20])
		return (ft_check_map((map + 21), ++nb_map));
	if (j == 4 && k == 4 && map[19] == '\n' && !map[20])
		return (TRUE);
	return (FALSE);
}

int		ft_testriminos(char *s)
{
	int i;
	int touch;

	i = 0;
	touch = i;
	while (i != 21)
	{
		if (s[i] == '#' && (i - 1 >= 0) && s[i - 1] == '#')
			touch++;
		if (s[i] == '#' && (i + 1 < 21) && s[i + 1] == '#')
			touch++;
		if (s[i] == '#' && (i - 5 >= 0) && s[i - 5] == '#')
			touch++;
		if (s[i] == '#' && (i + 5 < 21) && s[i + 5] == '#')
			touch++;
		i++;
	}
	if (s[20] && (touch == 6 || touch == 8))
		return (ft_testriminos(s + 21));
	if (touch == 6 || touch == 8)
		return (TRUE);
	error("error");
	return (FALSE);
}
