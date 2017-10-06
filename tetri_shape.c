/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:40:56 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/06 16:23:06 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_coord		*coord_new(int x, int y)
{
	t_coord	*new;

	new = (t_coord *)ft_memalloc(sizeof(t_coord));
	new->x = x;
	new->y = y;
	return (new);
}

void		min_max(char *buf, t_coord *min, t_coord *max)
{
	int		counter;

	counter = 0;
	while (counter < 20)
	{
		if (buf[counter] == '#')
		{
			if ((counter / 5) < min->y)
				min->y = counter / 5;
			if ((counter / 5) > max->y)
				max->y = counter / 5;
			if ((counter % 5) < min->x)
				min->x = counter % 5;
			if ((counter % 5) > max->x)
				max->x = counter % 5;
		}
		counter++;
	}
}

t_shape		*shape_new(char **shape, int width, int height, char bukva)
{
	t_shape *new;

	new = (t_shape *)ft_memalloc(sizeof(t_shape));
	new->shape = shape;
	new->width = width;
	new->height = height;
	new->bukva = bukva;
	return (new);
}

t_shape		*identify_shape(char *buf, char bukva)
{
	t_coord		*min;
	t_coord		*max;
	char		**shape;
	t_shape		*myshape;
	int			counter;

	min = coord_new(3, 3);
	max = coord_new(0, 0);
	min_max(buf, min, max);

	shape = (char **)ft_memalloc((max->y - min->y) + 2);
	counter = 0;
	while (counter < (max->y - min->y + 1))
	{
		*shape = ft_strnew(max->x - min->x + 1);
		ft_strncpy(*shape, (buf + (min->x) + (counter + min->y) * 5), (max->x - min->x + 1));
		counter++;
		shape++;
	}
	*shape = NULL;
	shape -= counter;
	myshape = shape_new(shape, max->x - min->x + 1, max->y - min->y + 1, bukva);
	ft_memdel((void**)&min);
	ft_memdel((void**)&max);
	return (myshape);
}
