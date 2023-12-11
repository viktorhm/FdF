### COMPILATION ###
CC      = gcc
CFLAGS  = -Wall -Werror -g
CLINKS  = -lXext -lX11 -lm

### EXECUTABLE ###
NAME   = fdf

### INCLUDES ###

HEADER = includes
SRC_PATH  = sources
MLX = minilibx-linux
LIBMLX = $(MLX)/libmlx.a

### SOURCE FILES ###

SOURCES = main.c \
		  draw.c \
		  ft_atoi.c \
		  ft_split.c \
		  get_next_line.c \
		  get_next_line_utils.c \
		  read_file.c \

### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(SRCS:.c=.o)


### RULES ###

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(CFLAGS) -o $@ $^ $(CLINKS)

$(LIBMLX):
	make -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re, fclean, clean
