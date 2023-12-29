CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRCS = shell.c parser.c executor.c utils.c
OBJS = $(SRCS:.c=.o)
TARGET = hsh

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

