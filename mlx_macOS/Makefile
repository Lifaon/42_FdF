#
#

RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	@echo "$(RED)rm -rf$(EOC) objs from mlx_macOS"
	@rm -rf $(OBJ)

del:
	@echo "$(RED)rm -rf$(EOC) $(NOM)"
	@rm -rf $(NOM)

fclean: clean del

re: fclean all
