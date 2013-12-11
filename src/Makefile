CC = gcc
CFLAGS = -Os -Wall -Werror -Wextra -Wno-unused -std=c99 -pedantic `pkg-config --cflags glew glfw3`
LDFLAGS = `pkg-config --static --libs glew glfw3`

EXE = main

.PHONY: all clean

all: $(EXE)

$(EXE): $(addsuffix .c, $(EXE))
	$(CC) $(CFLAGS) $(addsuffix .c, $(EXE)) -o $(EXE) $(LDFLAGS)
	strip --strip-all $(EXE)

clean:
	-@rm -rf $(EXE)
