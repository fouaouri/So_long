src = functions/get_next_line_utils.c	functions/get_next_line.c	ft_printf/ft_strlen.c\
		ft_printf/ft_printf.c	ft_printf/ft_putnbr.c	ft_printf/ft_unsigned.c\
		ft_printf/ft_lower_hex.c	ft_printf/ft_putstr.c	ft_printf/ft_upper_hex.c\
		ft_printf/ft_pntr.c	ft_printf/ft_putchar.c	animate_player.c	check_path.c\
		check_map.c	main.c	print_error.c check_of_animations.c so_long.c

O_files = $(src:.c=.o)

NAME = so_long

$(NAME) : $(O_files)
	 gcc $(O_files) -lmlx -framework OpenGl -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

clean : 
	rm -rf $(O_files)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

launch : $(NAME)
	./$(NAME)