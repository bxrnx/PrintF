/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:41:17 by bemelend          #+#    #+#             */
/*   Updated: 2024/01/31 17:58:55 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_select_format(va_list variables_inf, const char str, int *byte)
{
	if (str == '%')
		ft_print_percentage(byte);
	if (str == 'c')
		ft_putchar(va_arg(variables_inf, int), byte);
	if (str == 'd' || str == 'i')
		ft_print_decimal_and_int(va_arg(variables_inf, int), byte);
	if (str == 'p')
		ft_print_pointer(va_arg(variables_inf, unsigned long long), byte);
	if (str == 's')
		ft_print_string(va_arg(variables_inf, char *), byte);
	if (str == 'u')
		ft_print_unsigned(va_arg(variables_inf, unsigned int), byte);
	if (str == 'X')
		ft_print_x(va_arg(variables_inf, unsigned int), 'X', byte);
	if (str == 'x')
		ft_print_x(va_arg(variables_inf, unsigned int), 'x', byte);
}

int	ft_printf(const char *str, ...)
{
	va_list	variables_inf;
	int		i;
	int		bytedev;
	char	c;

	bytedev = 0;
	va_start(variables_inf, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			c = str[++i];
			ft_select_format(variables_inf, c, &bytedev);
			i++;
		}
		else
		{
			ft_putchar(str[i], &bytedev);
			i++;
		}
	}
	va_end(variables_inf);
	return (bytedev);
}

/*int	main(void)
{
	int byte;
	byte = 0;

	byte = ft_printf( " %x \n", 0);

	printf(" %x \n", 0);
	return (0);
}*/