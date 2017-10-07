/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:02:38 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/07 14:08:15 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_list *list)
{
	t_list	*next;
	t_shape	*shape;

	while (list)
	{
		shape = (t_shape *)list->content;
		next = list->next;
		free_shape(shape);
		ft_memdel((void **)&list);
		list = next;
	}
}

void	free_shape(t_shape *shape)
{
	int	height;

	height = 0;
	while (height < shape->heigth)
	{
		ft_memdel((void **)&shape->shape[height]);
		height++;
	}
	ft_memdell((void **)&shape->shape);
	ft_memdell((void **)&shape);
}
