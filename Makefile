# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tim <tim@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/25 12:11:47 by tim           #+#    #+#                  #
#    Updated: 2020/04/30 13:17:48 by tim           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS 		= ft_strlen.s

OBJS		= $(SRCS:.s=.o)

# FLAGS			= -Wall -Weror -Wextra
NASM_FLAGS 		= nasm -f macho64
NAME			= libasm.a
TEST			= test

all:

	$(NASM_FLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:		
				rm -rf $(OBJS)

fclean:		clean
				rm -rf $(NAME) $(TEST)

re:			fclean $(NAME)

test: 		$(NAME)
			gcc -o $(TEST) main.c $(NAME)