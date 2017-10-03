/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:25:57 by ynenakho          #+#    #+#             */
/*   Updated: 2017/10/03 16:32:41 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

char *open_file(int fd)
{
	char	*buf;
	int		ret;

	buf = ft_strnew(21);
	if (i = read(fd, buf, 21) >= 20)
		return (buff);
	return (NULL);
}
