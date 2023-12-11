### COMPILATION ###
CC      = gcc 
FLAGS  = -Wall -Werror

### EXECUTABLE ###
NAME   = fdf

### INCLUDES ###

OBJ_PATH  = objs
HEADER = includes
SRC_PATH  = sources
MLX = minilibx-linux

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
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))


### RULES ###

all: lib tmp $(NAME)

lib:
	@make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(MLX) -o $@ $^  -lmlx -lXext -lX11 -lm
	@

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	

clean:
	@rm -rf $(OBJ_PATH)

fclean:
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	

re: fclean
	@$(MAKE) all -j

.PHONY: temporary, re, fclean, clean
