#Including the configs for the project
include config.mk

# Compiler settings
CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Build structure
NAME := $(OUTFILE)

OBJ := $(SRC:$(SRC_DIR)%=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@
	@echo "Making obj dir and files.."

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "Project ready for use."

cleanobj:
	@rm -f $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@rm -rf $(OBJ_DIR)

clean: cleanobjdir
	@echo "Cleaning object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Project file removed"

re: fclean all

.PHONY: all clean fclean re
