SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = obj/

PROJECT_NAME = simu
CC = gcc
CFLAGS = -Wall -Wextra -I$(INC_DIR)

SRC_FILES = $(wildcard $(SRC_DIR)*.c) $(SRC_DIR)main.c
OBJ_FILES = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))

all: init build

init:
	mkdir -p $(OBJ_DIR)
	
build: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(PROJECT_NAME) $^

$(OBJ_DIR)main.o: $(SRC_DIR)main.c $(SRC_DIR)test.h

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(PROJECT_NAME)

rebuild: clean build

.PHONY: all build clean rebuild