#include "ft_printf.h"

void	ft_print_percentage(int *byte)
{
	ft_putchar('%', byte);
}

int	ft_putchar(char c, int *byte)
{	
	*byte = *byte + 1;
	return (write(1, &c, 1));
}

void	ft_putnbr(int n, int *byte) //imprimir números con write
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', byte);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, byte);
		ft_putchar(((nb % 10) + '0'), byte);
	}
	else
		ft_putchar((nb + '0'), byte);
}

int	ft_print_decimal_and_int(float n, int *byte)
{
	float	decimal_part;

	decimal_part = n - (int)n;
	ft_putnbr((int)n, byte);
	ft_putchar('.', byte);
	ft_putnbr(decimal_part * 100000, byte);
	return 0;
}

void ft_free_ptr(char **ptr) {
    free(*ptr);
    *ptr = NULL;
}

char ft_decimalToHexDigit(int digit)
{
    if (digit >= 0 && digit <= 9)
        return digit + '0';
    else
        return (digit - 10 + 'A');
}

int ft_hex_len(unsigned long numhex)
{
    int i;

    i = 0;
    while (numhex > 0)
    {
        numhex = numhex / 16;
        i++;
    }
    return i;
}

int ft_decimalToHexReverse(unsigned int decimal, char hex[])
{
    int i;

    i = 0;
    while (decimal > 0 || i == 0) {  // Asegura que se añadan ceros a la izquierda
        int remainder = decimal % 16;
        hex[i++] = ft_decimalToHexDigit(remainder);
        decimal /= 16;
    }

    // Añadir '0x' al principio
    hex[i++] = 'x';
    hex[i++] = '0';

    // Revertir la cadena
    int start = 0;
    int end = i - 1;
    while (start < end)
    {
        // Intercambiar caracteres
        char temp = hex[start];
        hex[start] = hex[end];
        hex[end] = temp;
        start++;
        end--;
    }
    return i; // Devuelve la longitud de la cadena generada
}

int ft_print_pointer(unsigned long pointeraddress, int *byte) {
    char *numhex;
    int i;

    if (!pointeraddress)
        return ft_putchar('0', byte) + ft_putchar('x', byte) + ft_putchar('0', byte) + ft_putchar('0', byte);

    numhex = (char *)malloc((ft_hex_len(pointeraddress) + 3) * sizeof(char));

    if (numhex == NULL)
        return -1;
    i = ft_decimalToHexReverse(pointeraddress, numhex);
    int j = 0;
    while (j < i) {
        ft_putchar(numhex[j++], byte);
    }
    ft_free_ptr(&numhex);
    return 0;
}

int	ft_print_string(char *s, int *byte)
{
	int	i;

	i = -1;
	if (!s)
		return ('\0');
	while (s[++i])
		ft_putchar(s[i], byte);
	return (i);
}

void ft_print_unsigned(unsigned int n, int *byte)
{

    if(n > 10)
    {
        n = n / 10;
        ft_print_unsigned(n, byte);
    }
    ft_putchar(n, byte);
    if (n <= 9)
        ft_putchar((n + '0'), byte);
}

char decimal_to_hex_digit(int digit, char type)
{
    if (digit >= 0 && digit <= 9)
        return digit + '0';
    if (type == 'X')
        return (digit - 10 + 'A');
    else
        return (digit - 10 + 'a');
}

int ft_decimal_to_hex_reverse(unsigned int decimal, char hex[], char type)
{
    int index = 0;
    while (decimal > 0)
    {
        int remainder = decimal % 16;
        hex[index] = decimal_to_hex_digit(remainder, type);
        decimal /= 16;
        index++;
    }
    // Terminar la cadena
    hex[index] = '\0';
    // Revertir la cadena
    int start = 0;
    int end = index - 1;
    while (start < end)
    {
        // Intercambiar caracteres
        char temp = hex[start];
        hex[start] = hex[end];
        hex[end] = temp;
        start++;
        end--;
    }
    return index; // Devuelve la longitud de la cadena generada
}

int ft_print_x(unsigned int n, char type, int *byte)
{
    char *num;
    int i;
    
    if (!n)
        return ft_putchar('0', byte) + ft_putchar('x', byte) + ft_putchar('0', byte) + ft_putchar('0', byte);
    num = (char *)malloc((ft_hex_len(n) + 1) * sizeof(char));
    
    if (num == NULL)
    {
        // Manejo de error si malloc falla
        return (-1);
    }

    ft_decimal_to_hex_reverse(n, num, type);
    i = 0;
    while (num[i])
    {    
        ft_putchar(num[i], byte);
        i++;
    }
    ft_free_ptr(&num);
    return 0;
}