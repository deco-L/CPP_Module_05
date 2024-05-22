# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2024/05/22 17:21:51 by csakamot         ###   ########.fr        #
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

COUNT		= 0

##--------Makefile rule--------##
all:prev ${NAME}

prev:
				@printf "prev progress\n"

${NAME}:${OBJS}
				@printf "\nobject file				compiled"
				@$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)%.o:$(SRCDIR)%.cpp
				@printf "\r\e[0m"
				@$(eval COUNT = $(shell echo $$(($(COUNT) + 1))))
				@printf "["
				@for i in {1..10}; do if [ $$i -le $(COUNT) ]; then printf "$(AQUA)=\e$(RESET)"; else printf " "; fi; done
				@printf "]"
				@mkdir -p $(OBJDIR)
				@$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
				@${RM} -rf ${OBJDIR}
				@printf "object file				removed\n"

fclean:clean
				@${RM} -rf ${NAME}

re:fclean all

exe:re
				@make -s clean

.PHONY:all clean fclean re exe
##-----------------------------##
