#include "ft_printf.h"

int ft_print_unsigned(unsigned int n, int *byte)
{
    unsigned int len;

    if(n > 10)
    {
        n = n / 10;
        ft_print_unsigned(n, byte);
    }
    ft_putchar(n, byte);
    if (n <= 9)
        ft_putchar((n + '0'), byte);
}