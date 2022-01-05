NAME	=	fight
SRCS	=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS	=	$(SRCS:.cpp=.o)
CC		=	clang++
FLAGS	=	-Wall -Werror -Wextra -pedantic -std=c++98
INCS	=	.

all:		$(NAME)

$(NAME):	$(OBJS)
			${CC} ${FLAGS} -o $(NAME) $(OBJS)

%.o:		%.cpp
			${CC} ${FLAGS} -c -I${INCS} $< -o $@

clean:
			${RM} $(OBJS)

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all .c.o clean fclean re
