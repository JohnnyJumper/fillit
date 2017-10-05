/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:26:17 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/05 15:14:34 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int fd;
	char *buf;

	if (argc)
		;
	if(!(fd = open(argv[1], O_RDONLY)))
	{
		ft_putstr("Error reading the file\n");
	}
	while ((buf = open_file(fd)))
	{
		if (check_map(buf))
		{
			ft_putstr("invalid map\n");
			return(1);
		}
	}
	ft_putstr("Valid map");
	return (0);
}
