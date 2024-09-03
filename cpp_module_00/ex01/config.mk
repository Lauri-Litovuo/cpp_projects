# Exec name
OUTFILE := phonebook

# Source directory
S:= srcs/

# Object directory
O := objs/

# Include directory
I := incl/

# Source files
SRC := \
		$SMain.cpp $SPhoneBook.cpp $SContact.cpp

# Include directories
CXXFLAGS += -I$I

# Libraries to link (add -L for library directories and -l for libraries)
LDFLAGS :=

SRC_DIR := $S
OBJ_DIR := $O
INC_DIR := $I
