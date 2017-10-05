/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:25:57 by ynenakho          #+#    #+#             */
/*   Updated: 2017/10/05 15:13:19 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *open_file(int fd)
{
	char	*buf;
	int		ret;

	buf = ft_strnew(21);
	if ((ret = read(fd, buf, 21) >= 20))
		return (buf);
	return (NULL);
}

int	check_map(char *buf)
{
	int	hash_counter;
	int dot_counter;
	int	line_counter;
	int counter;

	counter = 0;
	hash_counter = 0;
	dot_counter = 0;
	line_counter = 0;
	while (counter < 21)
	{
		if (buf[counter] == '#')
			hash_counter++;
		if (buf[counter] == '.')
			dot_counter++;
		if (buf[counter] == '\n')
			line_counter++;
		counter++;
	}
	return (((hash_counter != 4) || (dot_counter != 12) || (line_counter != 5)) ? 1 : 0);
}

