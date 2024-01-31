/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:35:30 by bemelend          #+#    #+#             */
/*   Updated: 2024/01/31 17:58:56 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_print_decimal_and_int(long long n, int *byte)
{
	ft_putnbr((int)n, byte);
	return (0);
}

int	ft_print_string(char *s, int *byte)
{
	int		i;

	i = -1;
	if (!s)
	{
		write (1, "(null)", 6);
		*byte = *byte + 6;
		return (0);
	}
	while (s[++i])
		ft_putchar(s[i], byte);
	return (0);
}
