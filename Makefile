CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = main.c executor.c prompt.c utils.c cd.c builtins.c signals.c file_operators.c string_handlers.c env_handlers.c execute.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = my_shell

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)

