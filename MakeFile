CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = programa

SRCS = main.c \
       CentroPesquisa.c \
       function_call.c \
       PokeLista.c \
       Pokemon.c \
       Treinador.c

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