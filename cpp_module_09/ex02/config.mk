# Exec name
OUTFILE := mutantstack

# Compiler settings
CXX := c++

# Source directory
S:= ./srcs/

# Object directory
O := objs/

# Include directory
I := ./incl/

# Source files
SRC := \
		$Smain.cpp

# Include directories
CXXFLAGS += -Wall -Wextra -Werror -std=c++23 -I$I

# Libraries to link (add -L for library directories and -l for libraries)
LDFLAGS :=

SRC_DIR := $S
OBJ_DIR := $O
INC_DIR := $I
