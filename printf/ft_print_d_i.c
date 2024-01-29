/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:58:12 by bemelend          #+#    #+#             */
/*   Updated: 2023/11/09 17:59:53 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
	int 	decimal_bytes;

	decimal_part = n - (int)n;
	ft_putnbr((int)n, byte);
	ft_putchar('.', byte);
	ft_putnbr(decimal_part * 100000, byte);
	return 0;
}