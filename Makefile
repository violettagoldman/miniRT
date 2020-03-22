NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ifeq ($(D), 1)
    CFLAGS += -g3 -fsanitize=address
endif
MLXFLAGS = -framework OpenGL -framework AppKit -Lminilibx -lmlx
MLX = ./minilibx/libmlx.a

INC_DIR = ./inc/
SRC_DIR = ./src/
MLX_DIR = ./minilibx/

SRC = ${wildcard src/*.c}
OBJ = ${patsubst src/%.c, obj/%.o, ${SRC}}

all: $(NAME)

$(MLX):
	@printf "\033[0;32mMaking miniRT by Violetta Goldman...\033[0m\r"
	@make -C ./minilibx &> /dev/null

$(NAME): ${MLX} ${OBJ}
	@${CC} ${CFLAGS} ${MLXFLAGS} ${OBJ} -o ${NAME}
	@echo "\033[32;1mminiRT by Violetta Goldman is done \xE2\x9C\x94\033[0m          "

./obj/%.o: ./src/%.c
	@mkdir -p ./obj
	@${CC} ${CFLGS} -c $< -o $@

test: ${NAME} ${OBJ} ${SRC_DIR}main.c
	@./${NAME}

run:
	@./${NAME} $1

norme:
	@norminette ${INC_DIR} ${SRC_DIR}

clean:
	@rm -rf obj
	@make clean -C ./minilibx
	@echo "\033[32;1mCleaned miniRT \xE2\x9C\x94\033[0m"

fclean:	clean
	@rm -rf ${NAME} miniRT miniRT.dySM
	@make fclean -C ./minilibx
	@echo "\033[32;1mForced cleaned miniRT \xE2\x9C\x94\033[0m"

re:	fclean all

.PHONY: clean fclean all re
