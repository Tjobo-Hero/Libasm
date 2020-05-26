# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tim <tim@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/25 12:11:47 by tim           #+#    #+#                  #
#    Updated: 2020/05/26 16:07:35 by tim           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

## PIMPED MAKEFILE ##

# COLORS #

# This is a minimal set of ANSI/VT100 color codes
_END		=	\x1b[0m
_BOLD		=	\x1b[1m
_UNDER		=	\x1b[4m
_REV		=	\x1b[7m

# Colors
_GREY		=	\x1b[30m
_RED		=	\x1b[31m
_GREEN		=	\x1b[32m
_YELLOW		=	\x1b[33m
_BLUE		=	\x1b[34m
_PURPLE		=	\x1b[35m
_CYAN		=	\x1b[36m
_WHITE		=	\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\x1b[40m
_IRED		=	\x1b[41m
_IGREEN		=	\x1b[42m
_IYELLOW	=	\x1b[43m
_IBLUE		=	\x1b[44m
_IPURPLE	=	\x1b[45m
_ICYAN		=	\x1b[46m
_IWHITE		=	\x1b[47m

SRCS 		= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_read.s ft_write.s ft_strdup.s

OBJS		= $(SRCS:.s=.o)

FLAGS			= -Wall -Werror -Wextra
NASM_FLAGS 		= nasm -f macho64
NAME			= libft.a
TEST			= TEST

RM 				= rm -rf

%.o: 			%.s
				@$(NASM_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
				@echo "🍾🥂$(_BOLD) $(_GREEN)ALL FILES COMPILED$(_END)🥂🍾"

clean:		
				@$(RM) $(OBJS)
				@echo "$(_YELLOW)'"$(OBJS)"' DELETED $(_END)❌"

fclean:			clean
				@$(RM) $(NAME) $(TEST)
				@echo "$(_YELLOW)'"$(NAME)"''"$(TEST)"' DELETED $(_END)💔"

re:				fclean $(NAME)

test: 			$(NAME)
				@gcc $(FLAGS) -o $(TEST) main.c $(NAME)
				@echo "🕺$(_BOLD)$(_BLUE)'"$(TEST)"' CREATED$(_END)🕺"
				@echo "🤞$(_BOLD)$(_BLUE)RUNNING TEST$(_END)🤞"
				@./TEST