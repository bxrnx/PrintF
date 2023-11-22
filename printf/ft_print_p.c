/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:11:02 by bemelend          #+#    #+#             */
/*   Updated: 2023/11/22 14:25:30 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	decimal_to_hex_digit(int digit)
{
	if (digit >= 0 && digit <= 9)
	{
		return (digit + '0');
	}
	else
		return (digit - 10 + 'A');
}

int	ft_hex_len(unsigned long numhex)
{
	int	i;

	i = 0;
	while (numhex > 0)
	{
		numhex = numhex / 16;
		i++;
	}
	return (i);
}

int	decimal_to_hex_reverse(unsigned int decimal, char hex[])
{
	int		index;
	int		remainder;
	char	temp;
	int		start;
	int		end;

	index = 0;
	while (decimal > 0)
	{
		remainder = decimal % 16;
		hex[index] = decimalToHexDigit(remainder);
		decimal /= 16;
		index++;
	}
	hex[index] = '\0';
	start = 0;
	end = index - 1;
	while (start < end)
	{
		temp = hex[start];
		hex[start++] = hex[end--];
		hex[end] = temp;
	}
	return (index);
}

int	ft_print_pointer(unsigned long pointeraddress)
{
	char	*numhex;
	int		bytes;

	bytes = 0;
	if (!pointeraddress)
		return (write(1, "0x0", sizeof(char) * 3));
	numhex = (char *)malloc((ft_hex_len(pointeraddress) + 1) * sizeof(char));
	if (numhex == NULL)
		return (-1);
	bytes = decimalToHexReverse(pointeraddress, numhex);
	ft_free_ptr(&numhex);
	return (bytes);
}

/*int main()
{
    unsigned long pointeraddress = 0xDEADBEEF;

    int result = print_pointer(pointeraddress);

    if (result == -1) {
        fprintf(stderr, "Error en la asignación de memoria.\n");
        return 1;
    }

    printf("Longitud de la cadena generada: %d\n", result);

    return 0;
}*/