/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:16:59 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/07 14:27:07 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

typedef struct	s_map
{
	int		size;
	char	**array;
}				t_map;

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
int				open_file(char **argv);
int				check_map(char *buf);
int				check_connection(char *buf);
int				check_place(char *buf);
t_coord			*coord_new(int x, int y);
void			min_max(char *buf, t_coord *min, t_coord *max);
t_shape			*shape_new(char **shape, int width, int height, char bukva);
t_shape			*identify_shape(char *buf, char bukva);
void			ft_printlst(t_list *list);
void			free_list(t_list *list);
void			free_shape(t_shape *shape);


#endif
