# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 09:12:32 by lruiz-es          #+#    #+#              #
#    Updated: 2024/05/04 10:16:24 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# SOURCE FILES
# ******INSERT HERE IDENTIFICATION FOR SOURCE FILES***********************
SRCFILES = push_swap.c
#
#
#*******INSERT HERE INNER LIBRARY DIRECTORIES TO COMPILE******************
LIBDIRS = libft ft_printf
#
#
#
#********************CONFIGURATION OF THIS MAKEFILE***********************
#DEBUGGIN FLAGS
#UNCOMMENT NEXT LINE FOR DEBUGGIN
#CC_DEBUG_FLAGS = -g -fsanitize=address
#
#********************DONT EDIT FROM HERE**********************************
#MAKE MACRO VARIABLES FOR MAKEFILE WORKING
#DIRS STRUCTURE FOR SOURCES AND OBJECTS, AND LIBRARY NAMES
SRCDIR = .
OBJDIR = .
OBJFILES = $(SRCFILES:%.c=%.o)
OBJ = $(addprefix $(OBJDIR)/, $(OBJFILES))
LIBHEADERS = $(LIBDIRS:%=%.h)
LIBFILES = $(LIBHEADERS:%.h=%.a)
#MACRO VARIABLES FOR COMPILERS, FLAGS, ETC*******************************
CC = cc
CCFLAGS = -Wall -Werror -Wextra
.PHONY: all clean fclean re
all : $(NAME)
	

clean:
	@rm $(OBJ)
	@rm $(LIBHEADERS)
	@rm $(LIBFILES)

fclean: clean
	@for dir in $(LIBDIRS); do ; cd dir; make fclean; cd ..; done

re: fclean all
	

#****************************MAKEFILE END******************************
