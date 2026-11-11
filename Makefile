CC     = gcc
SRC    = main.c
CFLAGS = -Wall -std=c99

ifeq ($(OS),Windows_NT)
    TARGET = jeu.exe
    LIBS   = -lraylib -lopengl32 -lgdi32 -lwinmm
    RM     = del /Q
else
    TARGET = jeu
    LIBS   = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    RM     = rm -f
endif

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET)

.PHONY: all run clean
