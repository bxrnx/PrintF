#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int decimal_to_hex_reverse(unsigned int decimal, char hex[], char type)
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

int ft_print_x(unsigned int n, char type)
{
    char *num;
    int bytes;

    bytes = 0;
    if (!n)
        return write(1, "0x0", sizeof(char) * 3);
    num = (char *)malloc((ft_hex_len(n) + 1) * sizeof(char));
    
    if (num == NULL)
    {
        // Manejo de error si malloc falla
        return (NULL);
    }

    bytes = decimal_to_hex_reverse(n, num, type);
    ft_free_ptr(&num);
    return (bytes);
}

int main()
{
    unsigned int number = 255; // Reemplaza con el número que desees convertir
    char type = 'X'; // 'x' para minúsculas, 'X' para mayúsculas

    int result = ft_print_x(number, type);

    if (result == -1) {
        fprintf(stderr, "Error en la asignación de memoria.\n");
        return 1;
    }

    printf("Resultado: %d\n", result);

    return 0;
}