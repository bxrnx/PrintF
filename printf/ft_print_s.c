/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printString.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:35:28 by bemelend          #+#    #+#             */
/*   Updated: 2023/11/09 18:11:13 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *s, int *byte)
{
	int	i;

	i = -1;
	if (!s)
		return ('\0');
	while (s[++i])
		ft_putchar(s[i], byte);
	return (i);
}

int main()
{
	int *byte;
	
	ft_print_string("hermano q cojones", &byte);
	return 0;
}
