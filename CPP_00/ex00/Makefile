NAME = megaphone
SRCS = megaphone.cpp\

RM = rm -rf
OBJ = $(SRCS:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJ)
		   g++ $(CFLAG) $(OBJ) -o $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		 $(RM) $(NAME)
re : fclean all
