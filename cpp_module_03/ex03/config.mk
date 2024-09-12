# Exec name
OUTFILE := DiamondTrap

# Compiler settings
CXX := g++

# Source directory
S:= ./srcs/

# Object directory
O := objs/

# Include directory
I := ./incl/

# Source files
SRC := \
		$Smain.cpp $SClapTrap.cpp $SScavTrap.cpp $SFragTrap.cpp $SDiamondTrap.cpp

# Include directories
CXXFLAGS += -Wall -Wextra -Werror -std=c++11 -I$I

# Libraries to link (add -L for library directories and -l for libraries)
LDFLAGS :=

SRC_DIR := $S
OBJ_DIR := $O
INC_DIR := $I
