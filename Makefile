MAKEFLAGS += --silent
CC = cc
FLAGS = -Wall -Wextra -Werror
SO_LONG = so_long
FT_PRINTF = ft_printf/libftprintf.a
MINILIBX = minilibx/libmlx.a
MINILIBX_PATH = ./minilibx/
PRINTF_PATH = ./ft_printf/
LIB = -L${PRINTF_PATH} -lftprintf -L${MINILIBX_PATH} -lmlx -lXext -lX11
HEADER = -I so_long.h
OBJS = ft_game.c ft_map.c ft_utils.c ft_checkmap.c ft_mlx.c ft_isplayable.c ft_img.c ft_update.c ft_monster.c ft_utils2.c ft_end.c
OBJS_O = ${OBJS:.c=.o}

all: ${MINILIBX} ${FT_PRINTF} ${SO_LONG}
	echo "\033[7;32m~| Tous les fichiers sont à jour ! |~\033[0m"\

${FT_PRINTF}:
	make -sC ${PRINTF_PATH} all \
                && echo "\033[1;32m~| Compilation de la lib : OK |~\033[0m"\
                || echo "\033[1;31m~| Compilation de la lib : Erreur |~\033[0m"

${MINILIBX}:
	make -sC ${MINILIBX_PATH} \
                && echo "\033[1;32m~| Compilation de la Minilibx : OK |~\033[0m"\
                || echo "\033[1;31m~| Compilation de la Minilibx : Erreur |~\033[0m"

${SO_LONG}: ${OBJS_O}
	${CC} ${FLAGS} ${OBJS_O} ${LIB} ${HEADER} -o ${SO_LONG} \
                && echo "\033[1;32m~| Compilation du $@ : OK |~\033[0m"\
                || echo "\033[1;31m~| Compilation du $@ : Erreur |~\033[0m"

clean:
	make -sC ${PRINTF_PATH} fclean
	make -sC ${MINILIBX_PATH} clean
	rm -f ${OBJS_O}\
                && echo "\033[1;33m~| Nettoyage des .o : OK |~\033[0m"\
                || echo "\033[0;31m~| Compilation du $@ : Erreur |~\033[0m"


fclean: clean
	rm -f ${SO_LONG} \
                && echo "\033[1;33m~| Nettoyage des executables : OK |~\033[0m"\
                || echo "\033[0;31m~| Compilation du $@ : Erreur |~\033[0m"

re: fclean all

