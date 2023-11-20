NAME 		= libftprintf.a

LIB_PATH 	= ./library
LIBFT 		= ./libft/libft.a
LIBFTPRINTF	= ${LIB_PATH}/ft_printf.h
LIBS 		= -lftprintf

CC 			= gcc

FLAGS 		= -Wall -Werror -Wextra

REMOVE 		= rm -f
INCLUDE 	= -I ${LIB_PATH}

SRCS_PATH 	= ./printf

SRCS 		= 	$(SRCS_PATH)/ft_printf.c \
				$(SRCS_PATH)/ft_print_character.c \
				$(SRCS_PATH)/ft_print_percentage.c \
				$(SRCS_PATH)/ft_print_string.c \
				$(SRCS_PATH)/ft_print_deciaml_and_int.c \
				$(SRCS_PATH)/ft_print_unsigned.c \
				$(SRCS_PATH)/ft_print_pointer.c \
				$(SRCS_PATH)/ft_strlen.c \
				$(SRCS_PATH)/ft_print_x.c \

OBJS 		= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			ar -rcs $(NAME) $(OBJS)

$(LIBFT):
			make bonus -C libft
			cp $(LIBFT) $(NAME)

.c.o:
			$(CC) -c ${FLAGS} $< -o ${<:.c=.o} ${INCLUDE}

clean:
			make clean -C libft
			$(REMOVE) $(OBJS)

fclean:
			make fclean -C libft
			$(REMOVE) $(OBJS)
			$(REMOVE) $(NAME)

re: fclean all

norm:
			norminette

.PHONY: re all clean fclean norm