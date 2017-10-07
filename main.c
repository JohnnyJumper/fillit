/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:26:17 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/07 15:24:19 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{


	if (argc != 2)
	{
		ft_putstr("usage: fillit [map_file]\n");
		return (0);
	}
	if (open_file(argv))	
		ft_putstr("error\n");
	return (0);
}
