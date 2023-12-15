CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SOURCES = error_handling.c execute.c helpers.c main.c shell.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = hsh

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(CFLAGS) $^ -o $@

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJECTS) $(EXECUTABLE)

