CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MMD -MP -g

SRC_FILES	=	main.cpp Contact.cpp PhoneBook.cpp

INCLUDES	=	PhoneBook.hpp Contact.hpp

COMPILER	=	c++

OBJDIR		=	objs
OBJS		=	$(addprefix $(OBJDIR)/, $(SRC_FILES:.cpp=.o))

NAME		=	phonebook

COLOR = \033[1;32m
RESET = \033[0m

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(COMPILER) $(OBJS) -o $(NAME)
	@echo "$(COLOR)COMPILED!$(RESET)"

$(OBJDIR)/%.o	:	%.cpp $(INCLUDES)
	@mkdir -p $(dir $@)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

c	:	clean
clean	:
	@rm -rf $(OBJDIR)
	@echo "$(COLOR)OBJECT FILES REMOVED$(RESET)"

f	: fclean
fclean	:	clean
	@rm -rf $(NAME)
	@echo "$(COLOR)EXECUTABLES REMOVED$(RESET)"

re	: fclean all
	@echo "$(COLOR)RE_MADE!$(RESET)"

run	:	all
	@./$(NAME)

rerun	:	re all
	@./$(NAME)

val	:	all
	valgrind --track-origins=yes ./$(NAME)