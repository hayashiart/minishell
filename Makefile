CC = clang

RM = rm -rf

NAME = prog

#FT_PRINTF = ft_printf/

LIB_PATH = libft/

OBJ_PATH = objects/

#PRINT_SRC = $(addprefix $(FT_PRINTF), \
#		ft_fonctions1.c ft_fonctions2.c ft_printf.c ft_putchar.c ft_putnbr_hexa_up.c ft_putnbr_hexa.c ft_putnbr.c ft_putstr.c \
#)

SRCS = main.c \
		ft_echo.c \
		ft_cd.c \
		ft_env.c \
		ft_pwd.c \
		ft_exit.c \
		ft_unset.c \
		ft_export1.c \
		ft_export2.c \
		ft_export3.c \
		#$(PRINT_SRC)

OBJ	= ${SRCS:.c=.o}

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

CFLAGS	= -Wall -Wextra -Werror #-g -fsanitize=address 

#.c.o:
#	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(LIB_PATH)libft.a -o $(NAME)

libft/libft.a:
	make -C $(LIB_PATH)

all: ${NAME}

clean:
	make -C $(LIB_PATH) clean
	${RM} ${OBJ_PATH}

fclean: clean
	make -C $(LIB_PATH) fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re