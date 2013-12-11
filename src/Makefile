CC = gcc
CFLAGS = -O3 -Wall -Werror -Wextra -std=c99 -pedantic `pkg-config --cflags glfw3`
LDFLAGS = `pkg-config --static --libs glfw3`

EXE = main

.PHONY: all clean

all: $(EXE)

$(EXE): $(addsuffix .c, $(EXE))
	$(CC) $(CFLAGS) $(addsuffix .c, $(EXE)) -o $(EXE) $(LDFLAGS)

clean:
	-@rm -rf $(EXE)
