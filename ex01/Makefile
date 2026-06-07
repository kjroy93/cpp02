###########################################
#             VARIABLES                   #
###########################################

NAME			=	fixed_number
OBJ_DIR			=	obj
SRC				= 	src/Fixed.cpp	\
					main.cpp
INCLUDES		=	include
CPP				=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98 -I$(INCLUDES) -g
OBJ				=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

###########################################
#                 RULES                   #
###########################################

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling Fixed Pointer 42"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

###########################################
#               CLEANING                  #
###########################################

clean:
	@echo "Removing object files"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Removing executables"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re