/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:12:03 by bemelend          #+#    #+#             */
/*   Updated: 2024/01/30 17:40:36 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int n, int *byte)
{
	if (n > 10)
	{
		n = n / 10;
		ft_print_unsigned(n, byte);
	}
	ft_putchar(n, byte);
	if (n <= 9)
		ft_putchar((n + '0'), byte);
}
