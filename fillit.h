/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:16:59 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/07 18:20:10 by jtahirov         ###   ########.fr       */
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

void			print_map(t_map *map);
t_map			*alloc_map(int size);
int				sq_rt(int i);
void			free_map(t_map *map);
char			**ft_create_shape_base(void);
t_shape			*t_shapenew(char *shape, int height, int width, char bukva);
t_list			*open_file(int fd);
int				check_map(char *buf, int *flag);
int				check_connection(char *buf);
int				check_place(char *buf);
t_coord			*coord_new(int x, int y);
void			min_max(char *buf, t_coord *min, t_coord *max);
t_shape			*shape_new(char **shape, int width, int height, char bukva);
t_shape			*identify_shape(char *buf, char bukva);
void			ft_printlst(t_list *list);
void			free_shape(t_shape *shape);
int				solve_map(t_map *map, t_list *list);
t_map			*solve(t_list *list);
int				place(t_map *map, t_shape *shape, int x, int y);
void			put(t_map *map, t_shape *shape, t_coord *coord, char bukva);

#endif
