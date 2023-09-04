
AR = @ar -rc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

CC = @cc

SRCS = so_long.c check_map.c get_next_line.c get_next_line_utils.c ft_printf.c

all :
	${CC} ${CFLAGS} ${SRCS} -lmlx -framework OpenGL -framework AppKit -o so_long

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} $(NAME) pipex

re : fclean all