/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:25:57 by ynenakho          #+#    #+#             */
/*   Updated: 2017/10/07 18:47:20 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*open_file(int fd)
{
	char	*buf;
	int		ret;
	t_list	*list;
	char	bukva;
	int		flag;

	list = NULL;
	bukva = 'A';
	buf = ft_strnew(21);
	flag = 0;
	while((ret = read(fd, buf, 21)) >= 20)
	{
		if (check_map(buf, &flag))
			return(NULL);
		ft_lstpush(&list, ft_lstnew((void *)identify_shape(buf, bukva++),
					sizeof(t_shape)));
		ft_bzero(buf, 21);
	}
	if	(ret != 0 || flag != 1)
		return (NULL);
	return (list);
}

int		check_check(int hash_counter, int dot_counter, int line_counter)
{
	if (hash_counter != 4)
		return (1);
	if (dot_counter != 12)
		return (1);
	if (line_counter == 4)
		return (2);
	if (line_counter != 5)
		return (1);
	return (0);
}

int		check_map(char *buf, int *flag)
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
	if (check_check(hash_counter, dot_counter, line_counter) == 2)
	{
		if (*flag != 1)
			*flag = 1;
		else
			return (1);
	} else if (check_check(hash_counter, dot_counter, line_counter))
		return (1);
	if (check_connection(buf) || check_place(buf))
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
	/* if (buf[i] != '\n') */
	/* 	return (1); */
	return (0);
}
