/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:29:47 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/03/22 18:30:08 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fdcpy(char *av)
{
	char	*buffer;
	int		fd;

	buffer = ft_strnew(ft_fdlen(av));
	fd = open(av, O_RDONLY);
	read(fd, buffer, ft_fdlen(av));
	return (buffer);
}
