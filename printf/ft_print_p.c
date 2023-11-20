#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_free_ptr(char **ptr)
{
    free(*ptr);
    *ptr = NULL;
}

char decimalToHexDigit(int digit)
{
    if (digit >= 0 && digit <= 9)
    {
        return digit + '0';
    } else {
        return (digit - 10 + 'A');
    }
}

int ft_hex_len(unsigned long numhex)
{
    int i = 0;
    while (numhex > 0)
    {
        numhex = numhex / 16;
        i++;
    }
    return i;
}

int decimalToHexReverse(unsigned int decimal, char hex[])
{
    int index = 0;
    while (decimal > 0)
    {
        int remainder = decimal % 16;
        hex[index] = decimalToHexDigit(remainder);
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

int ft_print_pointer(unsigned long pointeraddress)
{
    char *numhex;
    int bytes = 0;

    if (!pointeraddress)
        return write(1, "0x0", sizeof(char) * 3);
    numhex = (char *)malloc((ft_hex_len(pointeraddress) + 1) * sizeof(char));
    
    if (numhex == NULL)
    {
        // Manejo de error si malloc falla
        return -1;
    }

    bytes = decimalToHexReverse(pointeraddress, numhex);
    ft_free_ptr(&numhex);
    return (bytes);
}

/*int main()
{
    unsigned long pointeraddress = 0xDEADBEEF; // Reemplaza esto con la dirección de puntero que desees imprimir

    int result = print_pointer(pointeraddress);

    if (result == -1) {
        fprintf(stderr, "Error en la asignación de memoria.\n");
        return 1;
    }

    printf("Longitud de la cadena generada: %d\n", result);

    return 0;
}*/