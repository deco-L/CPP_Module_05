# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2024/05/19 19:56:54 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##----Executable File Name-----##
NAME		= Bureaucrat
##-----------------------------##

##-----Directory Location------##
SRCDIR	= ./src/

INCDIR	= ./include/

OBJDIR	= objs/
##-----------------------------##

##------------Srcs-------------##
MAINSRC	=	main.cpp Bureaucrat.cpp

SRCS		= $(addprefix $(SRCDIR), ${MAINSRC})
##-----------------------------##

##-----------Object------------##
OBJS		= ${subst ${SRCDIR}, $(OBJDIR), ${SRCS:.cpp=.o}}
##-----------------------------##

##----------conpiler-----------##
CC			= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address
##-----------------------------##

##-----------archive-----------##
ARFLAG	= rcs
##-----------------------------##

##-------escape sequence-------##
RED			= \e[38;5;1m
GREEN		= \e[38;5;2m
ORANGE	= \e[38;5;3m
BLUE		= \e[38;5;4m
VIOLET	= \e[38;5;5m
AQUA		= \e[38;5;6m
WHITE		= \e[38;5;7m
GREY		= \e[38;5;8m
RESET		= \e[0m
##-----------------------------##

##--------Makefile rule--------##
all:${NAME}

${NAME}:${OBJS}
				@echo "object file				compiled"
				@$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)%.o:$(SRCDIR)%.cpp
				@mkdir -p $(OBJDIR)
				@$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
				@${RM} -rf ${OBJDIR}
				@echo "object file				removed"

fclean:clean
				@${RM} -rf ${NAME}

re:fclean all

exe:re
				@make -s clean

.PHONY:all clean fclean re exe
##-----------------------------##
