#Default compiler
CC=gcc
#Name of generated server executable
NAME=server

#Flags for compiler
CFLAGS = -Wall -g -I../include
LDFLAGS =-lconfig

#Take all *.c files under src directory
SOURCES = $(wildcard ../src/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):$(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(NAME)
