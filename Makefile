#OBJS specifies which files to compile as part of the project
OBJS = main.cpp Window.cpp

#CC specifies which compiler we're using
CC = g++

INCLUDE_DIR = -IC:\mingw64\include -I..\include

LIB_DIR = -LC:\mingw64\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = snake

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_DIR) $(LIB_DIR) $(LINKER_FLAGS) -o $(OBJ_NAME)