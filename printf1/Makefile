NAME	=	libftprintf.a
INCLUDE	= 	pintf.h

SRC		=	ft_printf.c					\
			ft_printf_utils_p.c			\
			ft_printf_utils_u.c			\
			ft_printf_utils_xX.c		\
			ft_printf_utils.c			\

OBJ		=	${SRC:.c=.o}

CC		=	gcc
RM		=	rm -f
AR		=	ar rc
RN		=	ranlib

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	${OBJ} 
	@echo "Compiling .."
	${AR} ${NAME} ${OBJ}
	${RN} ${NAME}
	@echo "Done !"

clean:
	@echo "Remove .o  ..."
	${RM} ${OBJ}
	@echo "Done !"

fclean: clean
	@echo "Remove lib ..."
	${RM} $(NAME)
	@echo "Done !"

re: fclean all  