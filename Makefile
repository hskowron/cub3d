CC	=	gcc

NAME =	cub3d

FLAGS =	-Wall -Wextra -Werror

MLX	=	-Lminilibx -lmlx -framework OpenGL -framework AppKit

SRC	=	cub3d.c gnl_utils.c rgb.c utils.c get_wall_images.c \
		get_ceiling_floor.c free.c wip_stuff.c

OBJECTS:=  $(SRC:c=o)

$(NAME): $(OBJECTS) | silence
	@make -C ./libftp
	@cp libftp/libftp.a libftp.a
	@$(CC) $^ $(CFLAGS) -L. -lftp $(MLX) -o $@
	@printf "\n		successfully compiled \n\n"

%.o: %.c
	$(CC) $(RDINC) $< -c $(CFLAGS) -o $@

all: $(NAME)

silence:
	@:

clean:
	@find . -type f -name '*.o' -delete
	@make -C ./libftp clean

fclean: clean
	@rm -f $(NAME)
	@rm -f libftp.a
	@make -C ./libftp fclean

re: fclean
	@make -C ./libftp fclean
	@make all

.PHONY: clean fclean re