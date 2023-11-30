# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 14:50:31 by jomirand          #+#    #+#              #
#    Updated: 2023/11/30 15:24:21 by jomirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

RESET   = \033[0m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

SRCS = 	main.cpp\
		Base.cpp\

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)
	clear
	@echo "$(GREEN)./ex02 executable is ready!$(RESET)"

clean:
	@$(RM) $(OBJS)
	clear
	@echo "$(RED)object files have been deleted!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	clear
	@echo "$(RED)object files and executable have been deleted$(RESET)"

re: fclean all