##
## Makefile
##

.PHONY: all clean fclean re

SRC_DIR := ./sources
HDR_DIR := ./headers


SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(shell find $(SRC_DIR) -name "*.o")
NAME := core-uprising

WARNINGS := -Wall -Wextra -Werror -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Wno-long-long -Wuninitialized -Wstrict-prototypes
LIBS := -lncurses
CFLAGS := -std=c89 -s -O2 -I$(HDR_DIR) $(WARNINGS) $(LIBS) -o $(NAME).bin

all:
	$(CC) $(SRCS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME).bin

re: fclean all
