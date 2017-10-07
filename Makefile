# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/11 13:01:35 by jtahirov          #+#    #+#              #
#    Updated: 2017/10/07 15:05:42 by jtahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCW = gcc -Wall -Wextra -Werror 
NAME = fillit
SRC =  main.c tetri_shape.c open_file.c solve.c map.c utility.c

OBJECT = $(SRC:.c=.o)

all: libft_compile $(NAME)

$(NAME):
	@echo "Compiling Project..."
	@$(GCCW) -I ./libft -c $(SRC)
	@$(GCCW) $(OBJECT) ./libft/libft.a -o $(NAME)
	@echo "Finished!"

libft_compile:
	@+$(MAKE) -C ./libft

libft_clean:
	@+$(MAKE) clean -C ./libft

libft_fclean:
	@+$(MAKE) fclean -C ./libft

clean: 
	@echo "Cleanning Project..."
	@/bin/rm -f $(OBJECT)
	@echo "Cleaned"

fclean: clean libft_fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft_clean libft_compile
