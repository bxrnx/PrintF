/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:12:03 by bemelend          #+#    #+#             */
/*   Updated: 2024/01/31 17:58:57 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned long n, int *byte)
{
	if (n < 0)
		n = -n;
	if (n > 9)
	{
		ft_print_unsigned((n / 10), byte);
		ft_putchar(((n % 10) + '0'), byte);
	}
	if (n <= 9)
		ft_putchar((n + '0'), byte);
}
