CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MMD -MP -g

SRC_FILES	=	tests.cpp Account.cpp

COMPILER	=	c++

OBJDIR		=	objs
OBJS		=	$(addprefix $(OBJDIR)/, $(SRC_FILES:.cpp=.o))

NAME		=	accountant

COLOR = \033[1;32m
RESET = \033[0m

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(COMPILER) $(OBJS) -o $(NAME)
	@echo "$(COLOR)COMPILED!$(RESET)"

$(OBJDIR)/%.o	:	%.cpp
	@mkdir -p $(dir $@)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

c	:	clean
clean	:
	@rm -rf $(OBJDIR)
	@echo "$(COLOR)SOURCE FILES REMOVED$(RESET)"

f	: fclean
fclean	:	clean
	@rm -rf $(NAME) out a.out
	@echo "$(COLOR)EXECUTABLES REMOVED$(RESET)"

re	: fclean all
	@echo "$(COLOR)RE_MADE!$(RESET)"

run	:	all
	@./$(NAME)

out	:	all
	@./$(NAME) > out

val	:	all
	valgrind ./$(NAME)

.phony	:	all c clean f fclean re run val
