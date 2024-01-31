/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_xX.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:35:30 by bemelend          #+#    #+#             */
/*   Updated: 2024/01/31 17:58:57 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	decimal_to_hex_digit(int digit, char type)
{
	if (digit >= 0 && digit <= 9)
		return (digit + '0');
	if (type == 'X')
		return (digit - 10 + 'A');
	else
		return (digit - 10 + 'a');
}

void	ft_decimal_to_hex_reverse(unsigned int decimal, char hex[], char type)
{
	int		index;
	int		remainder;
	int		start;
	int		end;
	char	temp;

	index = 0;
	while (decimal > 0)
	{
		remainder = decimal % 16;
		hex[index] = decimal_to_hex_digit(remainder, type);
		decimal /= 16;
		index++;
	}
	hex[index] = '\0';
	start = 0;
	end = index - 1;
	while (start < end)
	{
		temp = hex[start];
		hex[start] = hex[end];
		hex[end] = temp;
		start++;
		end--;
	}
}

int	ft_print_x(unsigned int n, char type, int *byte)
{
	char	*num;
	int		i;

	if (!n)
	{
		return (ft_putchar(('0'), byte));
	}
	num = (char *)malloc((ft_hex_len(n) + 1) * sizeof(char));
	if (num == NULL)
		return (-1);
	ft_decimal_to_hex_reverse(n, num, type);
	i = 0;
	while (num[i])
	{
		ft_putchar(num[i], byte);
		i++;
	}
	ft_free_ptr(&num);
	return (0);
}
