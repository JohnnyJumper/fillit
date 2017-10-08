/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:30:26 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/07 20:16:38 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_shape		*shape;

	if (!list)
		return (1);
	y = 0;
	shape = (t_shape *)list->content;
	while (y < map->size - shape->height + 1)
	{
		x = 0;
		while (x < map->size - shape->width + 1)
		{
			if (place(map, shape, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					put(map, shape, coord_new(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = sq_rt(ft_lstcount(list) * 4);
	map = alloc_map(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = alloc_map(size);
	}
	return (map);
}

int		place(t_map *map, t_shape *shape, int x, int y)
{
	int row;
	int col;

	row = 0;
	while (row < shape->width)
	{
		col = 0;
		while (col < shape->height)
		{
			if (shape->shape[col][row] == '#' \
					&& map->array[col + y][row + x] != '.')
				return (0);
			col++;
		}
		row++;
	}
	put(map, shape, coord_new(x, y), shape->bukva);
	return (1);
}

void	put(t_map *map, t_shape *shape, t_coord *coord, char bukva)
{
	int x;
	int y;

	x = 0;
	while (x < shape->width)
	{
		y = 0;
		while (y < shape->height)
		{
			if (shape->shape[y][x] == '#')
				map->array[coord->y + y][coord->x + x] = bukva;
			y++;
		}
		x++;
	}
	ft_memdel((void **)&coord);
}
