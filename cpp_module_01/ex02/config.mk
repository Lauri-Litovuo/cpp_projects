# Exec name
OUTFILE := brain

# Compiler settings
CXX := g++

# Source directory
S:= ./

# Object directory
O := objs/

# Include directory
I := ./incl/

# Source files
SRC := \
		$Smain.cpp

# Include directories
CXXFLAGS += -Wall -Wextra -Werror -std=c++11 -I$I

# Libraries to link (add -L for library directories and -l for libraries)
LDFLAGS :=

SRC_DIR := $S
OBJ_DIR := $O
INC_DIR := $I
