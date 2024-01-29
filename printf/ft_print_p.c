#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_free_ptr(char **ptr) {
    free(*ptr);
    *ptr = NULL;
}

char ft_decimalToHexDigit(int digit, int *byte)
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

int ft_decimalToHexReverse(unsigned int decimal, char hex[], int *byte)
{
    int i;

    i = 0;
    while (decimal > 0 || i == 0) {  // Asegura que se añadan ceros a la izquierda
        int remainder = decimal % 16;
        hex[i++] = ft_decimalToHexDigit(remainder, byte);
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
    i = ft_decimalToHexReverse(pointeraddress, numhex, byte);
    int j = 0;
    while (j < i) {
        ft_putchar(numhex[j++], byte);
    }
    ft_free_ptr(&numhex);
    return 0;
}

/*int main() {
    unsigned long pointeraddress = 0xDEADBEEF;
    int byte_count = 0;
    int *byte = &byte_count;

    int result = ft_print_pointer(pointeraddress, byte);

    if (result == -1) {
        fprintf(stderr, "Error en la asignación de memoria.\n");
        return 1;
    }

    printf("Total de bytes impresos: %d\n", byte_count);

    return 0;
}
*/