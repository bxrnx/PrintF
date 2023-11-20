#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_print_percentage(void);
int		ft_print_character(char c);
int		ft_print_string(char *s);
int		ft_print_unsigned(unsigned int n);
int		ft_print_decimal_and_int(float n);
int		ft_print_pointer(unsigned long pointeraddress);
int		ft_print_x(unsigned int n, char type);
int		ft_strlen(char *str);

#endif