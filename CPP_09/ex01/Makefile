NAME = RPN

SRCS = main.cpp RPN.cpp

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