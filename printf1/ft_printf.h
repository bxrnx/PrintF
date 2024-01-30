#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

void    ft_print_percentage(int *byte);
int	    ft_putchar(char c, int *byte);
void	ft_putnbr(int n, int *byte);
int	    ft_print_decimal_and_int(float n, int *byte);
int	    ft_print_decimal_and_int(float n, int *byte);
char    ft_decimalToHexDigit(int digit);
int     ft_hex_len(unsigned long numhex);
int		ft_decimalToHexReverse(unsigned int decimal, char hex[]);
int     ft_print_pointer(unsigned long pointeraddress, int *byte);
int	    ft_print_string(char *s, int *byte);
void    ft_print_unsigned(unsigned int n, int *byte);
void    ft_free_ptr(char **ptr);
int     ft_hex_len(unsigned long hexadecimal);
char    decimal_to_hex_digit(int digit, char type);
int     ft_decimal_to_hex_reverse(unsigned int decimal, char hex[], char type);
int     ft_print_x(unsigned int n, char type, int *byte);
void    ft_select_format(va_list variables_inf, const char str, int *byte);
int     ft_printf(const char *str, ...);
int	    ft_strlen(char *s);

#endif