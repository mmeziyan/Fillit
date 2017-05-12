/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:45:08 by juhallyn          #+#    #+#             */
/*   Updated: 2017/05/12 21:43:28 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/fillit.h"

char	**open_file(char *file)
{
	int		fd;
	int		ret;
	char	buff[BUFF + 1];
	char	*map;

	if ((fd = open(file, O_RDONLY)) == -1)
		error("open error");
	if ((ret = read(fd, buff, BUFF)) == -1)
		error("read error");
	buff[ret] = '\0';
	map = ft_strdup(buff);
	if ((ft_check_map(map, 1) != TRUE) || (ft_testriminos(map) != TRUE))
	{
		error("error");
		return (NULL);
	}
	return (split_map(map));
}

int		count_tetri(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i / 4);
}

char	***all_tetris(int nb_tetri, char **map)
{
	char	***tetri;
	int		i;
	int		n;
	char	c;

	c = 'A';
	i = -1;
	n = 0;
	tetri = (char ***)malloc(sizeof(char ***) * (nb_tetri + 80));
	tetri[nb_tetri + 80] = NULL;
	while (++i < nb_tetri)
	{
		tetri[i] = send_a_tetri(map, c);
		while (n < 4 && *map)
		{
			map++;
			n++;
		}
		n = 0;
		c++;
	}
	return (tetri);
}

t_coord	*init_coord(char ***map, int nb_tetri, t_coord *coord)
{
	int i;

	i = 0;
	if ((coord = (t_coord *)malloc(sizeof(t_coord *) * (nb_tetri * 2))) == NULL)
		error("error malloc init_coord");
	while (i < nb_tetri)
	{
		coord[i] = ft_xy(map[i], ft_line(map[i]), ft_column(map[i]));
		i++;
	}
	return (coord);
}

int		main(int argc, char **argv)
{
	char		***all_tetri;
	char		**file;
	int			nb_size[2];
	t_coord		*coord;
	char		**f_map;

	coord = NULL;
	if (check_arguments(argc) == FALSE)
		error("usage : ./fillit the_file");
	file = open_file(argv[1]);
	nb_size[0] = count_tetri(file);
	nb_size[1] = size_map(nb_size[0]);
	all_tetri = all_tetris(nb_size[0], file);
	coord = init_coord(all_tetri, nb_size[0], coord);
	free(all_tetri);
	f_map = new_map(nb_size[1]);
	while (place(nb_size[1], coord, nb_size[0], new_map(nb_size[1])) != TRUE)
		nb_size[1]++;
	return (TRUE);
}
