/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:07:39 by bemelend          #+#    #+#             */
/*   Updated: 2023/11/22 14:38:54 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_unsigned(unsigned int n)
{
	unsigned int	len;

	if (n > 10)
	{
		n = n / 10;
		ft_print_unsigned(n);
	}
	ft_putchar(n);
	if (n <= 9)
		ft_putchar(n + '0');
}
