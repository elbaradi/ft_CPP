NAME	=	program
SRCS	=	main.cpp Bureaucrat.cpp Form.cpp Intern.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
OBJDIR	=	objs
OBJS	=	$(SRCS:%.cpp=$(OBJDIR)/%.o)
CC		=	clang++
FLAGS	=	-Wall -Werror -Wextra -pedantic -std=c++98
INCS	=	.

all:		$(NAME)

$(NAME):	$(OBJS)
			${CC} ${FLAGS} -o $(NAME) $(OBJS)

$(OBJDIR)/%.o:	%.cpp
			@mkdir -p $(OBJDIR)
			${CC} ${FLAGS} -c -I${INCS} $< -o $@

clean:
			rm -rf $(OBJDIR)

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all .c.o clean fclean re
