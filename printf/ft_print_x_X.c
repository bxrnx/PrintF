#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_putchar(char c, int *byte)
{
  *byte = *byte + 1;
  return (write(1, &c, 1));
}

void ft_free_ptr(char **ptr)
{
    free(*ptr);
    *ptr = NULL;
}

int ft_hex_len(unsigned long hexadecimal)
{
    int i = 0;
    while (hexadecimal > 0)
    {
        hexadecimal = hexadecimal / 16;
        i++;
    }
    return i;
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

int ft_decimal_to_hex_reverse(unsigned int decimal, char hex[], char type, int *byte)
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
        return (NULL);
    }

    decimal_to_hex_reverse(n, num, type, byte);
    i = 0;
    while (num[i])
    {    
        ft_putchar(num[i], byte);
        i++;
    }
    ft_free_ptr(&num);
    return 0;
}

int main()
{
    unsigned int number = 255; // Reemplaza con el número que desees convertir
    char type = 'x'; // 'x' para minúsculas, 'X' para mayúsculas
    int byte_dev = 0;
    int *byte = &byte_dev;
    ft_print_x(number, type, byte);


    printf(" = %d\n", byte_dev);

    return 0;
}