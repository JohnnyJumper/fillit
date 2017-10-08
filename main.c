/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:26:17 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/07 18:01:33 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{

	t_list *list;
	int fd;

	if (argc != 2)
	{
		ft_putstr("usage: fillit [map_file]\n");
		return (1);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		ft_putstr("error\n");
		return (2);
	}
	if (!(list = open_file(fd)))
	{
		ft_putstr("error\n");
		return (3);
	}
	print_map(solve(list));
	return (0);
}
