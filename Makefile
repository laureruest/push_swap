# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 09:12:32 by lruiz-es          #+#    #+#              #
#    Updated: 2024/05/11 10:49:16 by lruiz-es         ###   ########.fr        #
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
CC_DEBUG_FLAGS = -g -fsanitize=address
#
#********************DONT EDIT FROM HERE**********************************
#MAKE MACRO VARIABLES FOR MAKEFILE WORKING
#DIRS STRUCTURE FOR SOURCES AND OBJECTS, AND LIBRARY NAMES
SRCDIR =.
OBJDIR =.
INCLUDEDIR = ./include
LIBDIR = ./lib
OBJFILES = $(SRCFILES:%.c=%.o)
OBJ = $(addprefix $(OBJDIR)/, $(OBJFILES))
SRC = $(addprefix $(SRCDIR)/, $(SRCFILES))
LIBHEADERS = $(LIBDIRS:%=%.h)
LIBFILES = $(addprefix $(LIBDIR)/, $(LIBHEADERS:%.h=%.a))
#MACRO VARIABLES FOR COMPILERS, FLAGS, ETC*******************************
CC = cc
CCFLAGS = -I $(INCLUDEDIR) -MMD -Wall -Werror -Wextra
.PHONY: all clean fclean re
all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CC_DEBUG_FLAGS) $(CCFLAGS) -o $@ $(^F) $(LIBFILES)

$(OBJ): $(SRC)
	@for DIR in $(LIBDIRS); do cd $${DIR}; make; cd ..; cp $${DIR}/*.h $(INCLUDEDIR); cp $${DIR}/*.a $(LIBDIR); done;
	$(CC) $(CC_DEBUG_FLAGS) $(CCFLAGS) -c $(?F)

clean:
	@rm -f $(OBJ)
	@rm -f $(LIBHEADERS)
	@rm -f $(LIBFILES)
	@rm -f $(LIBDIR)/*
	@rm -f $(INCLUDEDIR)/*

fclean: clean
	@for dir in $(LIBDIRS); do cd $${dir}; make fclean; cd ..; done

re: fclean all
	

#****************************MAKEFILE END******************************
