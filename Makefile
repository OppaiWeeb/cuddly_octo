CC	=	gcc
USE_WAYLAND_DISPLAY ?= TRUE

NAME	=	cuddly_octo

SRC	=	src/main.c\
	src/openfile.c\
	src/window.c\

INCLUDE_DIR	=	./include/
INCLUDE_LIB	=	./sub/raygui/src/

CFLAGS 	+=	-g2 -Wall -Wextra

OBJ	=	${SRC:.c=.o}

RM	=	rm -fr

LDFLAGS	=	-lraylib -lGL -lm -lpthread -ldl -lrt
# On X11 requires also below libraries
LDFLAGS += -lX11
# NOTE: It seems additional libraries are not required any more, latest GLFW just dlopen them
#LDLIBS += -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor

# On Wayland windowing system, additional libraries requires
ifeq ($(USE_WAYLAND_DISPLAY),TRUE)
	# LDFLAGS += -lwayland-client -lwayland-cursor -lwayland-egl -lxkbcommon
endif
all: ${NAME}

${NAME}: ${OBJ}
	gcc -iquote ${INCLUDE_DIR} -iquote ${INCLUDE_LIB} ${OBJ} -o ${NAME} ${LDFLAGS}

clean:
	${RM} ${OBJ}

clean_led:
	@ ${RM} *.led

fclean: clean clean_led
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re ${NAME}
