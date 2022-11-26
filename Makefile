CC	=	gcc

NAME	=	cuddly_octo

SRC	=	src/main.c\
	src/openfile.c\
	src/window.c\

INCLUDE_DIR	=	./include/

CFLAGS 	+=	-g2 -Wall -Wextra

OBJ	=	${SRC:.c=.o}

RM	=	rm -fr

LDFLAGS	=	-lraylib -lGL -lm -lpthread -ldl -lrt -lglfw -lX11
LDFLAGS += -lwayland-client -lwayland-cursor -lwayland-egl -lxkbcommon

all: ${NAME}

${NAME}: ${OBJ}
	gcc -iquote ${INCLUDE_DIR} -iquote ${INCLUDE_LIB} ${OBJ} -o ${NAME} ${LDFLAGS}

clean:
	${RM} ${OBJ}

clean_led:
	@ ${RM} *.led

clean_valgrind:
	@${RM} vgcore*

fclean: clean clean_led clean_valgrind
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re ${NAME} clean_led clean_valgrind
