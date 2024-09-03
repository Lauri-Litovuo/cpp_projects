# Exec name
OUTFILE := logger

# Source directory
S:= srcs/

# Object directory
O := objs/

# Include directory
I := incl/

# Source files
SRC := \
		$Stests.cpp $SAccount.cpp

# Include directories
CXXFLAGS += -I$I

# Libraries to link (add -L for library directories and -l for libraries)
LDFLAGS :=

SRC_DIR := $S
OBJ_DIR := $O
INC_DIR := $I
