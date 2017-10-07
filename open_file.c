/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:25:57 by ynenakho          #+#    #+#             */
/*   Updated: 2017/10/07 13:59:31 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		open_file(char **argv)
{
	int		fd;
	char	*buf;
	int		ret;
	t_list	*list;
	char	bukva;

	list = NULL;
	bukva = 'A';
	buf = ft_strnew(21);
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		ft_putstr("Error reading the file\n");
	}
	while (((ret = read(fd, buf, 21)) != 0))
	{
		if (check_map(buf))
		{
			ft_putstr("invalid map\n");
			return (1);
		}
		ft_lstadd(&list, ft_lstnew((void *)identify_shape(buf, bukva++),
					sizeof(t_shape)));
	}
	ft_printlst(list);
	return (0);
}

void	ft_printlst(t_list *list)
{
	t_list	*current;
	t_shape	*shape;

	current = list;
	while (current)
	{
		shape = (t_shape *)current->content;
		ft_print2d(shape->shape);
		ft_putchar('\n');
		current = current->next;
	}
}

int		check_map(char *buf)
{
	int	hash_counter;
	int dot_counter;
	int	line_counter;
	int counter;

	counter = 0;
	hash_counter = 0;
	dot_counter = 0;
	line_counter = 0;
	while (counter < 21)
	{
		if (buf[counter] == '#')
			hash_counter++;
		if (buf[counter] == '.')
			dot_counter++;
		if (buf[counter] == '\n')
			line_counter++;
		counter++;
	}
	if ((hash_counter != 4) || (dot_counter != 12) || (line_counter != 5)
			|| check_connection(buf) || check_place(buf))
		return (1);
	return (0);
}

int		check_connection(char *buf)
{
	int connect;
	int i;

	i = 0;
	connect = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#' && (i + 1) < 20)
				connect++;
			if (buf[i - 1] == '#' && (i - 1) >= 0)
				connect++;
			if (buf[i + 5] == '#' && (i + 5) < 20)
				connect++;
			if (buf[i - 5] == '#' && (i - 5) >= 0)
				connect++;
		}
		i++;
	}
	if (connect == 6 || connect == 8)
		return (0);
	return (1);
}

int		check_place(char *buf)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if ((i % 5) < 4)
		{
			if (buf[i] != '#' && buf[i] != '.')
				return (1);
		}
		else if (buf[i] != '\n')
			return (1);
		i++;
	}
	if (buf[i] != '\n')
		return (1);
	return (0);
}
