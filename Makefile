CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
RM = rm -rf
BETTY = betty
SRC = 	monty.c pall.c pint.c handle_op.c push.c pop.c swap.c\
	add.c nop.c free_stack.c
TARGET = monty



all:
	$(BETTY) $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

dev:
	$(CC) $(SRC) -o $(TARGET)
clean:
	$(RM) *~ \#*\# \.\#* \
        $(TARGET)

re: clean all