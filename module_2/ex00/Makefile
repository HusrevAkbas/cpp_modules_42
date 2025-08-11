CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MMD -MP -g

SRC_FILES	=	main.cpp Fixed.cpp

COMPILER	=	c++

OBJDIR		=	objs
OBJS		=	$(addprefix $(OBJDIR)/, $(SRC_FILES:.cpp=.o))
DEPS		=	$(addprefix $(OBJDIR)/, $(SRC_FILES:.cpp=.d))

NAME		=	fixedPointNumberIntro

COLOR = \033[1;32m
RESET = \033[0m

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(COMPILER) $(OBJS) -o $(NAME)
	@echo "$(COLOR)COMPILED!$(RESET)"

$(OBJDIR)/%.o	:	%.cpp
	@mkdir -p $(dir $@)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

-include $(DEPS)

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

val	:	all
	@valgrind --track-origins=yes ./$(NAME)

.phony	:	all c clean f fclean re run val
