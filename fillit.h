/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:16:59 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/02 21:50:39 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

typedef struct	s_shape
{
	char	*shape;
	int		height;
	int		width;
	char	bukva;
}				t_shape;

char			**ft_create_shape_base(void);
t_shape			*t_shapenew(char *shape, int height, int width, char bukva);

#endif
