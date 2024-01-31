/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:10:19 by bemelend          #+#    #+#             */
/*   Updated: 2024/01/31 17:58:58 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

void	ft_free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	ft_decimaltohexdigit(int digit)
{
	if (digit >= 0 && digit <= 9)
		return (digit + '0');
	else
		return (digit - 10 + 'a');
}

int	ft_hex_len(uintptr_t numhex)
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

int	ft_decimaltohexreverse(uintptr_t decimal, char hex[])
{
	int		i;
	int		remainder;
	char	temp;
	int		start;
	int		end;

	i = 0;
	while (decimal > 0 || i == 0)
	{
		remainder = decimal % 16;
		hex[i++] = ft_decimaltohexdigit(remainder);
		decimal /= 16;
	}
	hex[i++] = 'x';
	hex[i++] = '0';
	start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = hex[start];
		hex[start++] = hex[end];
		hex[end--] = temp;
	}
	return (i);
}

int	ft_print_pointer(uintptr_t pointeraddress, int *byte)
{
	char	*numhex;
	int		i;
	int		j;
	int		total;

	if (!pointeraddress)
	{
		total = 0;
		total += ft_putchar('0', byte);
		total += ft_putchar('x', byte);
		total += ft_putchar('0', byte);
		return (total);
	}
	numhex = (char *)malloc((ft_hex_len(pointeraddress) + 3) * sizeof(char));
	if (numhex == NULL)
		return (-1);
	i = ft_decimaltohexreverse(pointeraddress, numhex);
	j = 0;
	while (j < i)
		ft_putchar(numhex[j++], byte);
	ft_free_ptr(&numhex);
	return (0);
}
