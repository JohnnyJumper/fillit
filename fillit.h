/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:16:59 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/05 15:32:16 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

typedef struct	s_shape
{
	char	**shape;
	int		height;
	int		width;
	char	bukva;
}				t_shape;

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

char			**ft_create_shape_base(void);
t_shape			*t_shapenew(char *shape, int height, int width, char bukva);
char			*open_file(int fd);
int				check_map(char *buf);

#endif
