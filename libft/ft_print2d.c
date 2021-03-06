/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 03:17:11 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/07 13:54:38 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print2d(char **array)
{
	while (*array)
	{
		ft_putstr(*array);
		ft_putstr("\n");
		array++;
	}
}
