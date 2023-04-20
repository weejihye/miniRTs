#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+= -w -O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -cr $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "\033[32m****** Making mlx is done *******"

.c.o :
	@cc $(CFLAGS) -o $@ -c $?

.m.o :
	@cc $(CFLAGS) -o $@ -c $?

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
