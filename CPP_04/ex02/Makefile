NAME = abstract

SRCS = main.cpp\
	    Cat.cpp\
	    Dog.cpp\
		Animal.cpp\
		Brain.cpp\

RM = rm -rf
OBJ = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98


all : $(NAME)

$(NAME) : $(OBJ)
		   c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		 $(RM) $(NAME)
re : fclean all
