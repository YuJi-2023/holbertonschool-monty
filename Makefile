CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
RM = rm -rf
BETTY = betty
SRC = monty.c pall.c pint.c handle_op.c push.c pop.c\
	add.c free_stack.c swap.c nop.c sub.c
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
