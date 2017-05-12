/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:29:47 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/04/07 18:53:50 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fdlen(char *av)
{
	int		i;
	char	buffer[1];
	int		fd;

	i = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (1);
	while (fd)
	{
		if ((fd = read(fd, buffer, 1)) == -1)
			return (-1);
		i++;
	}
	return (i);
}
