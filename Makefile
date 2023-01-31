# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zeynepsasmaz <zeynepsasmaz@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 22:44:31 by zeynepsasma       #+#    #+#              #
#    Updated: 2022/12/26 22:44:31 by zeynepsasma      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET	=	\033[0m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RED		=	\033[31m

NAME = push_swap

SRCS =  main.c stack_func1.c stack_func2.c  control_edit.c utils.c \
		three_five.c radix.c free.c

OBJS = $(SRCS:.c=.o)

CC = @gcc -ggdb
MFLAGS =  ./libft/libft.a
AFLAGS =  -Wall -Wextra -Werror ./libft 
CFLAGS =  -Wall -Wextra -Werror

RM = rm -rf


all :$(MFLAGS) $(NAME)

$(MFLAGS):
	@make -C ./libft

$(NAME): $(OBJS)
	@echo "$(GREEN)>- 🌊Compiling...🌊 [$(NAME)] $(RESET)"
	@$(CC) $(OBJS) $(MFLAGS) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)>-🌊🌊🌊🌊🌊Finish..🌊🌊🌊🌊🌊 [$(NAME)] $(RESET)"

fclean : clean
	@echo "$(RED)>- 🌊🌊🌊🌊🌊Deleting...🌊🌊🌊🌊🌊 [$(NAME)] $(RESET)"
	@$(RM) ./libft/*.a
	@$(RM) ./*.a
	@$(RM) $(NAME)
	@echo "$(RED)>- 🌊🌊🌊Finish..🌊🌊🌊 [$(NAME)] $(RESET)"

clean :
	@$(RM) ./libft/*.o
	@$(RM) ./*.o
	@$(RM) $(OBJS)

re : fclean all

.PHONY : all fclean clean re
