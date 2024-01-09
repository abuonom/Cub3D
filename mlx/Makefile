#
#

NAME	=	../lib/libmlx.a
SRC		=	mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC		+=	mlx_png.c mlx_mouse.m
OBJ1	=	$(SRC:.c=.o)
OBJ		=	$(OBJ1:.m=.o)
CFLAGS	+=	-O2
LIB_DIR = ../lib

# add to match string put with X11 in size and position
CFLAGS	+=	-DSTRINGPUTX11

all:	$(NAME)

$(NAME):	$(OBJ)
	@if [ ! -d $(LIB_DIR) ]; then mkdir -p $(LIB_DIR); fi
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(NAME) $(OBJ) *~
	rm -f mlx_app
	rm -f ../lib/libmlx.a

re: clean all

.PHONY:	all clean re
