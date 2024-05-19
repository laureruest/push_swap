# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 09:12:32 by lruiz-es          #+#    #+#              #
#    Updated: 2024/05/19 12:55:39 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# SOURCE FILES
# ******INSERT HERE IDENTIFICATION FOR SOURCE FILES***********************
SRCFILES = push_swap.c doit.c
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
DEPDIR =.
INCLUDEDIR = include/
LIBDIR = lib/
OBJFILES = $(SRCFILES:%.c=%.o)
OBJ = $(addprefix $(OBJDIR)/, $(OBJFILES))
SRC = $(addprefix $(SRCDIR)/, $(SRCFILES))
DEP = $(SRC:%.c=%.d)
DEPS = $(addprefix $(DEPDIR)/, $(DEP))
LIBHEADERS = $(addprefix $(INCLUDEDIR), $(LIBDIRS:%=%.h))
LIBFILES = $(addprefix $(LIBDIR), $(LIBDIRS:%=%.a))

#MACRO VARIABLES FOR COMPILERS, FLAGS, ETC*******************************
CC = cc
CCFLAGS = -MMD -I $(INCLUDEDIR) -L $(LIBDIR) -Wall -Werror -Wextra
.PHONY: all clean fclean re
all : $(NAME)
	

$(NAME) : $(OBJ) $(LIBHEADERS) $(LIBFILES)
	$(CC) $(CC_DEBUG_FLAGS) $(CCFLAGS) -o $@ $(OBJ) $(LIBFILES) 

$(LIBHEADERS) $(LIBFILES) : |$(INCLUDEDIR) $(LIBDIR)
	for DIR in $(LIBDIRS); do cd $${DIR}; make; cd ..; cp $${DIR}/*.h $(INCLUDEDIR); cp $${DIR}/*.a $(LIBDIR); done;

$(INCLUDEDIR) : 
	@mkdir $(INCLUDEDIR)

$(LIBDIR) : 
	@mkdir $(LIBDIR)

$(DEPS) $(OBJ) : $(SRC) $(LIBHEADERS) 
	$(CC) $(CC_DEBUG_FLAGS) -MMD -I $(INCLUDEDIR) -c $?

clean :
	@rm -f $(OBJ)
	@rm -f $(LIBHEADERS)
	@rm -f $(LIBFILES)
	@rm -f $(DEPS)

fclean : clean
	@rm -f *.d
	@for DIR in $(LIBDIRS); do cd $${DIR}; make fclean; cd ..; done
	@rm -f $(NAME)
	@rm -rf $(INCLUDEDIR)
	@rm -rf $(LIBDIR)
	@rm -rf *.gch

re: fclean
	@make all

	

include $(DEPS)

#****************************MAKEFILE END******************************
