/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:26:17 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/05 22:02:01 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{


	if (argc)
		;
	if (!(open_file(argv)))	
		ft_putstr("Valid map");
	return (0);
}
