# Exec name
OUTFILE := btc

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
		$Smain.cpp $SBitcoinExchange.cpp

# Include directories
CXXFLAGS += -Wall -Wextra -Werror -std=c++20 -I$I

# Libraries to link (add -L for library directories and -l for libraries)
LDFLAGS :=

SRC_DIR := $S
OBJ_DIR := $O
INC_DIR := $I
