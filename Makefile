NAME = miniRT
CFLAGS = -Wall -Wextra -Werror -Ofast -flto -march=native
ifeq ($(D), 1)
    CFLAGS += -g3 -fsanitize=address
endif
GREEN = 
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	CC = clang
	MLXFLAGS = -lm -lbsd -lXext -lX11 -Lminilibx_linux -lmlx_Linux -pthread -D LINUX=1
	MLX = ./minilibx/libmlx.a
	MLX_DIR = ./minilibx_linux/
else
	CC = gcc
	MLXFLAGS = -framework OpenGL -framework AppKit -Lminilibx -lmlx -D LINUX=0
	MLX = ./minilibx/libmlx.a
	MLX_DIR = ./minilibx/
endif

SRC_DIR = ./src/

SRC = ${wildcard src/*.c}
SRC_GNL = ${wildcard src/get_next_line/*.c}
OBJ = ${patsubst src/%.c, obj/%.o, ${SRC}}
OBJ_GNL = ${patsubst src/get_next_line/%.c, obj/get_next_line/%.o, ${SRC_GNL}}

all: $(NAME)

$(MLX):
	@printf "\033[0;32mMaking miniRT by Violetta Goldman...\033[0m\r"
	@make -C ${MLX_DIR} > /dev/null 2>&1

$(NAME): ${MLX} ${OBJ} ${OBJ_GNL}
	@${CC} ${OBJ} ${OBJ_GNL} ${CFLAGS} ${MLXFLAGS} -o ${NAME}
	@echo "\033[32;1mminiRT by Violetta Goldman is done \342\234\224\033[0m          "

./obj/get_next_line/%.o: ./src/get_next_line/%.c
	@mkdir -p ./obj/get_next_line
	@${CC} ${CFLAGS} -c $< -o $@

./obj/%.o: ./src/%.c
	@mkdir -p ./obj
	@${CC} ${CFLAGS} -c $< -o $@

test: ${NAME} ${OBJ} ${OBJ_GNL} ${SRC_DIR}main.c
	@./${NAME} scenes/sphere.rt

run:
	@./${NAME} $1

norme:
	@norminette ${SRC_DIR} rt.h

clean:
	@rm -rf obj miniRT.bmp
	@make clean -C ${MLX_DIR} > /dev/null
	@echo "\033[32;1mCleaned miniRT \342\234\224\033[0m"

fclean:	clean
	@rm -rf ${NAME} miniRT miniRT.dySM
	#@make fclean -C ${MLX_DIR}
	@echo "\033[32;1mForced cleaned miniRT \342\234\224\033[0m"

re:	fclean all

.PHONY: clean fclean all re
