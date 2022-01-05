NAME	=	program
SRCDIR	=	srcs
SRCS	=	main.cpp span.cpp
OBJDIR	=	objs
OBJS	=	$(SRCS:%.cpp=$(OBJDIR)/%.o)
CC		=	clang++
FLAGS	=	-Wall -Werror -Wextra -pedantic -std=c++98
INCDIR	=	incs

all:		$(NAME)

$(NAME):	$(OBJS)
			${CC} ${FLAGS} -o $(NAME) $(OBJS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
			@mkdir -p $(OBJDIR)
			${CC} ${FLAGS} -c -I${INCDIR}/ $< -o $@

clean:
			rm -rf $(OBJDIR)

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all .c.o clean fclean re
