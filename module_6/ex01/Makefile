CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC_FILES	=	main.cpp Serializer.cpp

COMPILER	=	c++

OBJDIR		=	objs
OBJS		=	$(addprefix $(OBJDIR)/, $(SRC_FILES:.cpp=.o))
DEPS		=	$(addprefix $(OBJDIR)/, $(SRC_FILES:.cpp=.d))

NAME		=	serializer

RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BG_YELLOW	=	\033[1;43m
BG_RED		=	\033[3;4;101m
BG_CYAN		=	\033[3;4;46m
RESET		=	\033[0m

MSG_COMP	=	⠀⠀⠀⠀$(GREEN)COMPILED$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀
MSG_OBJS	=	$(YELLOW)OBJECT FILES REMOVED$(RESET)
MSG_EXT		=	⠀$(RED)EXECUTABLE REMOVED$(RESET)⠀
MSG_EMPTY	=	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

ifeq ($(firstword $(MAKECMDGOALS)),)
	MSG1:=$(MSG_COMP)
	MSG2:=$(MSG_EMPTY)
	MSG3:=$(MSG_EMPTY)
else ifneq ($(filter $(firstword $(MAKECMDGOALS)),all $(NAME)),)
	MSG1:=$(MSG_COMP)
	MSG2:=$(MSG_EMPTY)
	MSG3:=$(MSG_EMPTY)
else ifneq ($(filter $(firstword $(MAKECMDGOALS)),c clean),)
	MSG1:=$(MSG_OBJS)
	MSG2:=$(MSG_EMPTY)
	MSG3:=$(MSG_EMPTY)
else ifneq ($(filter $(firstword $(MAKECMDGOALS)),f fclean),)
	MSG1:=$(MSG_OBJS)
	MSG2:=$(MSG_EXT)
	MSG3:=$(MSG_EMPTY)
else ifneq ($(filter $(firstword $(MAKECMDGOALS)),re),)
	MSG1:=$(MSG_OBJS)
	MSG2:=$(MSG_EXT)
	MSG3:=$(MSG_COMP)
endif

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(COMPILER) $(OBJS) -o $(NAME)
	@echo "$(GREEN)COMPILED!$(RESET)"

ifeq ($(firstword $(MAKECMDGOALS)),)
	@echo "$(PIKACHU)"
else ifneq ($(filter $(firstword $(MAKECMDGOALS)),all $(NAME)),)
	@echo "$(PIKACHU)"
endif

$(OBJDIR)/%.o	:	%.cpp
	@mkdir -p $(dir $@)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

-include $(DEPS)

c	:	clean
clean	:
	@rm -rf $(OBJDIR) *_shrubbery
	@echo "$(GREEN)OBJECT FILES REMOVED$(RESET)"

ifneq ($(filter $(firstword $(MAKECMDGOALS)),c clean),)
	@echo "$(PIKACHU)"
endif

f	: fclean
fclean	:	clean
	@rm -rf $(NAME)
	@echo "$(GREEN)EXECUTABLES REMOVED$(RESET)"

ifneq ($(filter $(firstword $(MAKECMDGOALS)),f fclean),)
	@echo "$(PIKACHU)"
endif

re	: fclean all
	@echo "$(GREEN)RE_MADE!$(RESET)"

ifneq ($(filter $(firstword $(MAKECMDGOALS)),re),)
	@echo "$(PIKACHU)"
endif

run	:	all
	@./$(NAME)

val	:	all
	@valgrind --track-origins=yes ./$(NAME)

.phony	:	all c clean f fclean re run val

PIKACHU	=⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸$(BG_YELLOW)⣿⣷$(RESET)⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈$(BG_YELLOW)⣿⣿⣿⣿⣦$(RESET)⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀$(MSG1)⠀⠀⠀⠀⠀⢸$(BG_YELLOW)⣿⣿⣿⣿⣿⣦$(RESET)⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀$(MSG2)⠀⠀⠀⠀⠀⠀$(BG_YELLOW)⢿⣿⣿⡿⠿⣿⣿$(RESET)⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀$(MSG3)⠀⠀⠀⠀⠀⠀⠈$(BG_YELLOW)⣿⠏⠀⠀⠀⠉⠛⠳$(RESET)⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘$(BG_YELLOW)⣆⠀⠀⠀⠐⣄⠀⠙$(RESET)⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹$(BG_YELLOW)⣆⠀⠀⠀⠈⣆⠀⠈⢧$(RESET)⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻$(BG_YELLOW)⣧⠀⠀⠀⠈⢣⠀⠈⢳$(RESET)⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻$(BG_YELLOW)⣧⠀⠀⠀⠈⠱⡀⠀⢻$(RESET)⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙$(BG_YELLOW)⣧⠀⠀⠀⠀⠀⠀⡈⣧$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣘$(BG_YELLOW)⣷⣅⣀⡀⠀⠀⠙⠸$(RESET)⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠘$(BG_YELLOW)⢿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠉⠉⠉⠉⠉⠉⠉⠒⠒⠒⠲⠦$(RESET)⢤⣄⣀⡀⠀⠀⣀⡴$(BG_YELLOW)⠖⠋⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣧$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠙$(BG_YELLOW)⢿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠳$(RESET)⠞$(BG_YELLOW)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹$(RESET)⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠈$(BG_YELLOW)⠙⠛⠿⢿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙$(RESET)⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉$(BG_YELLOW)⠓⠦⢤⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⡘$(RESET)⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉$(BG_YELLOW)⠛⠛⠒⠒⠒⠒⢲⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⢿⣿⣆⠹⣽$(RESET)⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(BG_YELLOW)⣾⠀⠀⠀⠀⠀⠀⣴⣿⡿⢶⡀⠀⠀⠀⠀⠀⠀⢻⣾⠿⣿⡆⠙$(RESET)⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀$(BG_YELLOW)⣾⠓⠒⠶⠦⢤⣤$(RESET)⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(BG_YELLOW)⡇⠁⠀⠀⠀⠀⢸⣿⣿⣧⣼⣷⠀⠀⠀⠀⠀⠀⠀⠻⠶⠟⠀⡼⢻$(RESET)⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀\n\
⠀$(BG_YELLOW)⣿⠀⠀⠀⠀⠀⠀⠀⠈⡉⠙⠓⠲⠦⣤$(RESET)⣀⡀⠀⠀⠀⠀⠀⠀⠀$(BG_YELLOW)⣷⠀⠀⠀⠀⠀⠘⢿⣅⣈⣿⠏⠀⠀⠀⠀⠶⠂⠀⠀⠀⠀⢠⡇⢨$(RESET)⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀$(BG_RED)⣠⣶⣶⣷⣿⣿⣿⣿$(RESET)\n\
⠀$(BG_YELLOW)⢻⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠈⠉⠛⠲$(RESET)⢤⣄⡀⠀⠀$(BG_YELLOW)⢹⡄⢀⡶⠛⠙⠳⣦⠉⠉⠁⠀⠀⠀⡀⠀⣀⣤⣤⠇⠀⠀⢸⣡⡟$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(BG_RED)⣻⣿⣿⣿⣯⣽⣳⣿⣿⡿⣹$(RESET)\n\
⠀⢸$(BG_YELLOW)⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓$(RESET)⢦⣀$(BG_YELLOW)⢻⣼⡰⢄⠀⠀⠈⣧⠀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⣠⡿$(RESET)⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀$(BG_RED)⣤⣶⣿⣿⣿⣿⣿⠿⠛⢉⡿⠉$(RESET)⠀\n\
⠀⠸$(BG_YELLOW)⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨$(RESET)⠇⠹$(BG_YELLOW)⣷⣀⠀⠀⢀⡿⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣰⣿$(RESET)$(BG_CYAN)⣿⣿$(RESET)⣀⠀⠀⠀⠀⠀⢀$(BG_RED)⣤⣶⣿⣷⣿⣿⣿⣿⠿$(RESET)⢋⣁⣤⠾⠋⠀⠀⠀\n\
⠀⠀$(BG_YELLOW)⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠏$(RESET)⠀⠀⢈$(BG_YELLOW)⣿⠉⠉⠉⠀⠀⠀⣀⣀⣰⣦⣶⣾⡿⣻⣿$(RESET)$(BG_CYAN)⣿⣿⡟$(RESET)$(BG_YELLOW)⠈⠙⢓⣦$(RESET)$(BG_RED)⣴⣾⣿⣿⣿⣿⣿⣿⠟⠛$(RESET)⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀\n\
⠀⠀⢸$(BG_YELLOW)⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠏$(RESET)⠀⢀$(BG_YELLOW)⣴⣿⡇⠀⠀⠀⠀⢰⡿⢛⣛⣳⢽⣦⢀⣴$(RESET)$(BG_CYAN)⣿⣿⣿$(RESET)$(BG_YELLOW)⠟⣀⣴$(BG_RED)⣞⣯⣿⣿⣿⣿⣿⡿⠟$(RESET)⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀$(BG_YELLOW)⠛⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⣄⡀⠀⠀⠀⢠⡞$(RESET)⢀$(BG_YELLOW)⣴⣿⣿⣿⡇⠀⠀⠀⠀⠘⡏⠉⠀⠈⠉⢻⣿$(RESET)$(BG_CYAN)⣿⣿⡿$(BG_RED)⣿⣿⣿⣿⣿⣿$(RESET)$(BG_YELLOW)⡟⠋⠉$(RESET)$(BG_RED)⡟⠁$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠$(BG_YELLOW)⣷⠃⠀⠀⠀⢈⣹⣿⣿$(BG_RED)⣿⣿⣿$(RESET)$(BG_YELLOW)⣇⡂⠀⠀⠀⠀⣯⠀⠀⠀⣀$(RESET)$(BG_CYAN)⣿⣿⣻$(BG_RED)⣿⣿⣿⣿⣿⣿⣿$(RESET)$(BG_YELLOW)⣛⣁⣀⡼$(RESET)⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀$(BG_YELLOW)⡟⠀⠀⠀⣀⣴$(RESET)$(BG_RED)⣿⣿⣿⣿⡿⠷⠷⣿$(RESET)$(BG_YELLOW)⡘⠀⠀⠀⠀⣿$(RESET)$(BG_RED)⣦⣷⣿⣿⣿⣿⣿⣿⣿⣿⠿$(RESET)$(BG_YELLOW)⠛⠻⡍⠉⠉$(RESET)⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(BG_YELLOW)⡼⠇⠀⢀$(RESET)$(BG_RED)⡾⠛⠉⠁⠀⠀⠀⠀⠀⣾⣿⣧$(RESET)$(BG_YELLOW)⠀⠀⠀⠀⣿$(RESET)$(BG_RED)⣿⣿⣿⣿⣿⣿⡿⠟$(RESET)$(BG_YELLOW)⠋⠀⠀⠀⠠⡽⣦$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰$(BG_YELLOW)⠇⢀⢤$(RESET)$(BG_RED)⠞⡱⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣷$(RESET)$(BG_YELLOW)⣄⣀⣤$(RESET)$(BG_RED)⣿⣿⣿⣿⣿⡟$(RESET)$(BG_YELLOW)⠁⠀⠀⠀⠀⠀⠀⠀⠀⢼⢷$(RESET)⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉$(BG_RED)⣿⢠⠇⠀⠀⠀⠀⠀⠀⢀⣴⣶⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣤⡤$(RESET)$(BG_YELLOW)⣄⠀⠀⠀⠀⠀⠀⠲⠻⣆$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(BG_RED)⣿⢸⠀⠀⠀⠀⠀⠀⠀⠸⣄⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿$(RESET)$(BG_YELLOW)⠀⠀⠀⠀⠀⠀⠀⠀⢻$(RESET)⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸$(BG_RED)⡸⡄⠀⠀⠀⠀⠀⠀⠀⠙⢧⣨⠟⠁⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿$(RESET)$(BG_YELLOW)⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈$(BG_RED)⢧⢣⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⢀⣤⣿⣿⣿⣿⠿⠛$(RESET)$(BG_YELLOW)⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡇$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈$(BG_RED)⣿⢧⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⣿⠟⣿⡟$(RESET)$(BG_YELLOW)⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡿$(RESET)⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘$(BG_RED)⢯⡳⡄⠀⠀⠀⣠⣾⣿⣽⡿⠛⢡⣾$(RESET)$(BG_YELLOW)⠏⠀⠀⠀⢀⣀⣠⣤⠤⠤⠤⢤⢤⣀⠀⢀⣤⠾⣟$(RESET)⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑$(BG_RED)⠾⣶⣤⣀⡙⠾⠋⠁⢀⣠⡿$(RESET)$(BG_YELLOW)⢃⣀⣤⠶⠛⠋$(RESET)⠉⠀⠀⠀⠀⠀⠙$(BG_YELLOW)⢦⣀⠀⠀⢀⢀⣀⡻⠷⣦$(RESET)⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈$(BG_RED)⠛⠿⠷⣶⣶⢿⣟$(RESET)$(BG_YELLOW)⠋⣀⢄⣴⠋$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈$(BG_YELLOW)⠙⠛⠲⠶⠦⠿⠷⠛$(RESET)⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰$(BG_YELLOW)⡋⣱⣏⣡⠽⠟⠋$(RESET)⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n