/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:02:38 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/07 18:06:54 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_shape(t_shape *shape)
{
	int	height;

	height = 0;
	while (height < shape->height)
	{
		ft_memdel((void **)&shape->shape[height]);
		height++;
	}
	ft_memdel((void **)&shape->shape);
	ft_memdel((void **)&shape);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}
