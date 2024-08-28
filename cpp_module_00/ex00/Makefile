NAME = megaphone


S = srcs/
O = objs/

all: $(NAME)

.PHONY: all clean fclean re

CC = g++
CFLAGS += -Wall -Wextra -Werror
LDFLAGS +=

######################
##		MANDATORY 	##
######################

SRC = \
		$Smegaphone.cpp

OBJ = $(SRC:$S%=$O%.o)

$O:
	@mkdir -p $@
	@echo "Making obj dir and files.."

$(OBJ): | $O

$O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Project ready for use."

cleanobj:
	@rm -f $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@rm -rf $O


clean: cleanobjdir
	@echo "Cleaning object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Project file removed"

re: fclean all
