CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89
SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
TARGET := shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

