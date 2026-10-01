CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = programa

SRCS = main.c \
       sources/CentroPesquisa.c \
       sources/function_call.c \
       sources/PokeLista.c \
       sources/Pokemon.c \
       sources/Treinador.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
