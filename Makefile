NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ifeq ($(D), 1)
    CFLAGS += -g3 -fsanitize=address
endif
MLXFLAGS = -framework OpenGL -framework AppKit -Lminilibx -lmlx
MLX = ./minilibx/libmlx.a

SRC_DIR = ./src/
MLX_DIR = ./minilibx/

SRC = ${wildcard src/*.c}
SRC_GNL = ${wildcard src/get_next_line/*.c}
OBJ = ${patsubst src/%.c, obj/%.o, ${SRC}}
OBJ_GNL = ${patsubst src/get_next_line/%.c, obj/get_next_line/%.o, ${SRC_GNL}}

all: $(NAME)

$(MLX):
	@printf "\033[0;32mMaking miniRT by Violetta Goldman...\033[0m\r"
	@make -C ./minilibx &> /dev/null

$(NAME): ${MLX} ${OBJ} ${OBJ_GNL}
	@${CC} ${CFLAGS} ${MLXFLAGS} ${OBJ} ${OBJ_GNL} -o ${NAME}
	@echo "\033[32;1mminiRT by Violetta Goldman is done \xE2\x9C\x94\033[0m          "

./obj/get_next_line/%.o: ./src/get_next_line/%.c
	@mkdir -p ./obj/get_next_line
	@${CC} ${CFLAGS} -c $< -o $@

./obj/%.o: ./src/%.c
	@mkdir -p ./obj
	@${CC} ${CFLAGS} -c $< -o $@

test: ${NAME} ${OBJ} ${OBJ_GNL} ${SRC_DIR}main.c
	@./${NAME} scenes/shapes.rt

run:
	@./${NAME} $1

norme:
	@norminette ${SRC_DIR} rt.h

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
