NAME=fdf
CFLAGS=-Werror -Werror -Wall -O3
INCLUDE=includes/includes.h includes/struct.h includes/function.h includes/define.h
MAIN=main.c
MAINS=$(addprefix srcs/, $(MAIN))
CTRL=controls.c view.c
CTRLS=$(addprefix srcs/controls/, $(CTRL))
PARSE=parsing.c parsing_utils.c
PARSES=$(addprefix srcs/parsing/, $(PARSE))
DPY=display_utils.c display_utils2.c draw_line.c draw_tile.c color.c
DPYS=$(addprefix srcs/display/, $(DPY))
OBJS=$(PARSE:.c=.o) $(DPY:.c=.o) $(MAIN:.c=.o) $(CTRL:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo Making Libft
	@make -C libft
	@echo Making Libx
	@make -C minilibx_macos
	@echo Making Fdf
	@gcc $(CFLAGS) -Llibft -lft -Lminilibx_macos -lmlx \
	-framework OpenGL -framework Appkit \
	-o $(NAME) $(OBJS)

$(OBJS): $(MAINS) $(DPYS) $(PARSES) $(CTRLS) $(INCLUDE)
	@echo Making OBJ
	@gcc $(CFLAGS) -Iincludes -Ilibft/includes -Iminilibx_macos -c $(MAINS) $(DPYS) $(PARSES) $(CTRLS)

clean:
	@make -C libft clean
	@make -C minilibx_macos clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean