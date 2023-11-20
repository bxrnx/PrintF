/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:41:17 by bemelend          #+#    #+#             */
/*   Updated: 2023/11/09 18:11:38 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

static int  ft_arg_check(va_list arg, char c)
{
    int bytes;

    bytes = 0;
    if (c == '%')
        bytes += ft_print_percentaje(va_args(args, int));
    else if (c == 's')
		bytes += ft_print_string(va_arg(args, char *));
	else if (c == 'p')
		bytes += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		bytes += ft_prin_decimal_and_int(va_arg(args, int));
	else if (c == 'u')
		bytes += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		bytes += ft_print_x(va_arg(args, unsigned int), format);
	return (bytes);
}

int ft_printf(const char *str, ...)
{
	int			i;
	va_list		args;
	int			bytes;
	char c;

	i = 0;
	bytes = 0;
	va_start(args, str)
	while (str[i])
	{
		c = str[i + 1];
		if (str[i] == "%")
			bytes = bytes + ft_arg_check(args, c);
		else
			{
				bytes = bytes + write(1, &str[i], 1);
				i++;	
			}
	}
	va_end(args);
	return (bytes);
}

int main()
{
	char unisex[] = "anasheeeei";
	ft_printf("%s", unisex);
}