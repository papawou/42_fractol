NAME := fractol.out
CFLAGS := -Wall -Werror -Wextra
CC := gcc

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS := -Wall -Werror -Wextra -g -fdiagnostics-color=always
endif

SRC_DIR := ./src/
OBJ_DIR := ./obj/

SRC := main.c	t_img.c color.c utils.c fractal.c	camera.c	events.c	scene.c gradient.c
OBJ := ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${addprefix ${OBJ_DIR}, ${OBJ}}
	${CC} ${CFLAGS} $^ -I./includes -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

${OBJ_DIR}%.o : ${SRC_DIR}%.c
	${CC} ${CFLAGS} -I./includes -I/usr/include -Imlx_linux -c $< -o $@

clean :
	${RM} ${addprefix ${OBJ_DIR}, ${OBJ}}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re