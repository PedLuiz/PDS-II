CC = g++
CFLAGS = -std=c++14 -Wall

OBJ_DIR = build

all: main

$(OBJ_DIR)/aluno.o: aluno.hpp aluno.cpp
	$(CC) $(CFLAGS) -c aluno.cpp -o $(OBJ_DIR)/aluno.o

$(OBJ_DIR)/main.o: aluno.hpp main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJ_DIR)/main.o

main: $(OBJ_DIR)/main.o $(OBJ_DIR)/aluno.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/aluno.o -o main

clean:
	del /Q main.exe $(OBJ_DIR)/*.o