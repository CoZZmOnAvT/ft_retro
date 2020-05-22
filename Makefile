# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 15:52:32 by pgritsen          #+#    #+#              #
#    Updated: 2018/04/08 16:34:07 by pgritsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang++

CFLAGS	=	-Wextra -Werror -Wall -Os -O3 -flto=thin

NAME	=	ft_retro

SRC		=	main.cpp Asteroid.cpp Fregat.cpp GameEntity.cpp Player.cpp Enemy.cpp	\
			Game.cpp Shoot.cpp Border.cpp

HDRS	=	Asteroid.hpp Fregat.hpp GameEntity.hpp Player.hpp IGameEntity.hpp		\
			Enemy.hpp Game.hpp Shoot.hpp Border.hpp

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

OBJDIR	=	obj

LIBR	= -lncurses

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJ): $(OBJDIR)/%.o : %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
